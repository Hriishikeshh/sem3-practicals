//============================================================================
// Name        : DSL_practical.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class stack{
	char stk[50];
	int top;
	int size;
public:
	stack(){
		size=50;
		top=-1;
	}
	bool isempty(){
		if(top==-1){
			return true;
		}
		else{
			return false;
		}
	}
	void push(char val){
		if (top!=size-1){
			top++;
			stk[top]=val;
		}
		else{
			cout<<"Stack Overflow! ";
		}
	}
	char pop(){
		if(!isempty()){
			char x=stk[top];
			top--;
			return x;
		}
		else{
			cout<<"Stack Underflow! ";
			return 0;
		}
	}
	char getTop(){
		return stk[top];
	}
};

bool isoperand(char x){
	if(x=='+'|| x=='-'||x=='*'||x=='/'||x=='('|| x==')'){
		return false;
	}
	else{
		return true;
	}
}
int pre(char c){
	if(c=='+'||c=='-'){
		return 1;
	}
	else if(c=='*'|| c=='/'){
		return 2;
	}
	else if(c=='('){
		return 3;
	}
}

string post(string s){
	string post="";
	stack obj;
	int n=s.size();
	for (int i=0;i<n;i++){
		if (isoperand(s[i])){
			post=post+s[i];
		}
		else if(s[i]==')'){
			while(obj.getTop()!='('){
				post=post+obj.pop();
			}
			obj.pop();
		}
		else{
			if(obj.isempty()){
				obj.push(s[i]);
			}
			else{
				while(!obj.isempty()&& obj.getTop()!='('&& (pre(s[i])<=pre(obj.getTop()))){
					post=post+obj.pop();
				}
				obj.push(s[i]);
			}
		}
	}
		while(!obj.isempty()){
			post=post+obj.getTop();
			obj.pop();

	}
	return post;
}

int evaluation(string s){
	stack obj;
	int n=s.size();
	int c;
	for (int i=0;i<n;i++){
	if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
		cout<<"Enter the value of "<<s[i]<<":";
		cin>>c;
		obj.push(c);
	}
	else{
		int x1,x2,r;
		x2=obj.pop();
		x1=obj.pop();
		switch(s[i]){
		case '+':
			r=x1+x2;
			obj.push(r);
			break;
		case '-':
			r=x1-x2;
			obj.push(r);
			break;
		case '*':
			r=x1*x2;
			obj.push(r);
			break;
		case '/':
			r=x1/x2;
			obj.push(r);
			break;
		default:
			break;
		}
	}
}
	return obj.pop();
}

int main(){
	cout<<"Enter the balanced expression: ";
	string str,s;
	cin>>str;
	s=post(str);
	cout<<"\nPostfix Expression: "<<s<<endl;
	int result;
	result=evaluation(s);
	cout<<"Answer: "<<result;
}
