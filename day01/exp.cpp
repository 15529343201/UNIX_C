#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<cstring>

class Exp{
	stack<char> ops;//运算符栈
	stack<double> ds;//数据栈
	double v,lh,rh;//计算结果和临时操作数变量
	char op;//运算符
	public:
		double calinput(){//读取并计算表达式直到结束
			do{
				readdata();//读取数据
				skipspace();//跳过空白
			}while(readop());//读取运算符
			calremain();//处理栈中的剩余的运算符
			return v;
		}
		void readdata(){
			while(!(cin>>v)){//读取数据失败应该是'('
				cin.clear();
				cin>>op;//读取'('
				if(op!='(') throw string("在该出现数值的地方遇到了")+op;
				ops.push(op);
			}
			ds.push(v);
		}
		void skipspace(){
			while(cin.peek()==' ') cin.ignore();
		}
		bool readop(){//读取运算符，可能遇到')'或者'\n'
			while((op=cin.get())==')'){
				while(ops.top()!='('){//找栈里的'('
					rh=ds.top();ds.pop();//从栈中取得右操作数
					lh=ds.top();ds.pop();//从栈中取得左操作数
					ds.push(cal(lh,ops.top(),rh));//计算并入栈
					ops.pop();
				}
				ops.pop();//丢弃'('
			}
			if(op=='\n') return false;
			if(strchr("+-*/",op)==NULL)//无效运算符
				throw string("无效运算符")+op;
			while(!ops.empty()&&ops.top()!='('&&!prior(op,ops.top())){
					rh=ds.top();ds.pop();
					lh=ds.top();ds.pop();
					ds.push(cal(lh,ops.top(),rh));
					ops.pop();
			}
					ops.push(op);
					return true;
		}
		void calremain(){
			while(!ops.empty()){
				rh=ds.top();ds.pop();
				lh=ds.top();ds.pop();
				ds.push(cal(lh,ops.top(),rh));
				ops.pop();
			}
			if(ds.size()!=1) throw string("无效的表达式");
			v=ds.top();
			ds.pop();
		}
		double cal(double lh,char op,double rh){
			return op=='+'?lh+rh:op=='-'?lh-rh:op=='*'?lh*rh:lh/rh;
		}
		bool prior(char o1,char o2){
			return o1!='+'&&o1!='-'&&o2!='*'&&o2!='/';
		}
};


int main()
{
	Exp e;
	try{
		cout<<e.calinput()<<endl;
	}catch(const string& e){
		cout<<e<<endl;
	}
	return 0;
}



















/*四则表达式练习:输入一个表达式，计算表达式结果!*/
/*表达式计算思路一:
 * 1.如果有括号，先计算括号里面的。如果有多层括号，先算最里面的。
 * 2.如果有乘除法，先计算乘除法。从左向右以此计算
 * 3.如果有加减法，计算加减法。从左向右依次计算
 * 4.没有运算符了，这时候得到的就是计算结果了
 */
/*表达式计算思路二:
 * 1.准备两个栈，一个数据栈一个运算符栈。反复读取表达式：(2,3,4)
 * 2.如果是数，入数据栈
 * 3.如果是括号，入运算符栈。如果是右括号，反复从运算符栈顶取运算符和从数据栈里取两个数据进行计算把结果入数据栈，
 *   直到遇到栈顶是左括号为止。
 * 4.如果是运算符，先跟栈顶的运算符比，只要不高于栈顶优先级，就取出栈顶的运算符和数据栈的两个数据进行计算，
 *   把结果入数据栈，直到高于栈顶运算符优先级或者遇到左括号或者运算符栈空为止。
 * 5.处理栈中的运算符：取出栈顶的运算符和数据栈的两个数据进行计算把结果入数据栈，直到运算符栈空为止。
 * 6.这时数据栈中的数据就是计算结果
 */
/*表达式计算思路三:
 * 1.如果没有运算符，直接就是计算结果
 * 2.找优先级最低的运算符，以它为界把表达式分成左右两个表达式。
 * 3.分别计算左边表达式的值和右边表达式的值(递归)
 * 4.用这两个值和那个运算符进行运算得到最后结果
 */
