#include<iostream>
using namespace std;

class test{
    public:
        int a;
        mutable int b;
        test(){
            a=0;
            b=0;
        }
        void display() const{
            b=b+50;
            cout<<a<<endl;
            cout<<b;
        }
};
int main(){
    const test obj;
    obj.display();
}