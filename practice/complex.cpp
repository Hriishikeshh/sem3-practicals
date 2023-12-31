#include<iostream>
using namespace std;

class complex{
    int real,imag;
    public:
        complex(){real=0;imag=0;}
        complex(int a,int b){
            real=a;
            imag=b;
        }

        complex operator+(complex k){
            complex temp;
            temp.real=real+k.real;
            temp.imag=imag+k.imag;
            return temp;
        }
        complex operator-(complex k){
            complex temp;
            temp.real=real-k.real;
            temp.imag=imag-k.imag;
            return temp;
        }
};
int main(){
    complex ob1(3,4);
    complex ob2(10,2);
    complex ob3,ob4;
    ob3=ob1+ob2;
    ob4=ob1-ob2;
    cout<<"add :"<<ob3;
    cout<<"minus :"<<ob4;
}