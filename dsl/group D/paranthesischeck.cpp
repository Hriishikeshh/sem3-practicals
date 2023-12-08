#include<iostream>
#include<string>
using namespace std;

class stack{
    int size;
    int top;
    string* arr;

    public:
        stack(int size){
            this->size=size;
            arr=new string[size];
            top=-1;
        }

        void push(string data){
            if(size-top>0){
                top++;
                arr[top]=data;
            }
            else{
                cout<<"stack is full"<<endl;
            }
        }

        void pop(){
            if(top>=0){
                top--;
            }
            else{
                cout<<"stack is empty"<<endl;
            }
        }

        string getTop(){
            if(top>=0){
                return arr[top];
            }
            else{
                return "";  //empty string
            }
        }
};

int main(){
    string exp;
    exp="{a+b-(c-d)-a]}";
    int n=exp.length();

    stack st(n+1);
    string t;
    for(int i=0;i<n;i++){
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='['){
            t=exp[i];
            st.push(t);
        }
        else if(exp[i]=='}'|| exp[i]==')' || exp[i]==']'){
            if(exp[i]=='}' && st.getTop()=="{"){
                st.pop();
            }
            else if(exp[i]==']' && st.getTop()=="["){
                st.pop();
            }
            else if(exp[i]==')' && st.getTop()=="("){
                st.pop();
            }
            else{
                cout<<"mismatched brackets at :"<<i<<endl;
                return 0;
            }
        }
    }

    if(st.getTop()==""){
        cout<<"balanced brackets"<<endl;
    }
    else{
        cout<<"not balanced brackets at last"<<endl;
    }
}