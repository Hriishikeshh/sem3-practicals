#include<iostream>
using namespace std;

class sum{
    public:
        int operation(int a,int b){
            int c;
            c=a+b;
            return c;
        }
};

class subtract:public sum{
    public:
        int operation(int a,int b){
            int c;
            c=a-b;
            return c;
        }
};

int main(){
    sum obj;
    cout<<"sum :"<<obj.operation(1,2)<<endl;
    subtract obj2;
    cout<<"diff :"<<obj2.operation(1,2);
}