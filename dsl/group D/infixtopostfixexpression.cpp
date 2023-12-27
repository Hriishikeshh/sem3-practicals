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

        int prec(char c){

            if(c=='('){
                return 3;
            }
            else if(c=='^'){
                return 2;
            }
            else if(c=='/'||c=='*'){
                return 1;
            }
            else if(c=='+'||c=='-'){
                return 0;
            }
            else{
                return -1;
            }
        }
};

int main(){
    string exp,result;
    exp="(a+b*c)/(x+y/z)";
    int n=exp.length();

    stack st(n+1);
    for(int i=0;i<n;i++){
        string t;
        t=exp[i];

        if((t>="a" && t<="z") || (t>="A" && t<="Z")){
            result+=t;
        }

        else if(t=="{" || t=="(" || t=="["){
            st.push(t);
        }

        else if(t=="}"|| t==")" || t=="]"){
           if(st.getTop()!="[" && st.getTop()!="{" && st.getTop()!="("){
                result+=st.getTop();
                st.pop();
           }
           st.pop();
        }

        else{
            while(st.getTop()!="" && st.prec(t[0]) <= st.prec(st.getTop()[0])){
                result+=st.getTop();
                st.pop();
            }
            st.push(t);
        }

    }

    while(st.getTop()!=""){
        result+=st.getTop();
        st.pop();
    }
    cout << "Postfix expression: " << result << endl;
}