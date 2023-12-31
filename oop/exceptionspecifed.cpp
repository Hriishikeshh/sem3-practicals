#include<iostream>
using namespace std;

void f() throw(int,double){
        throw(9.9);
}

int main(){
    try{
        f();
    }
    catch(int i){
        cout<<"integer handled";
    }
    catch(double i){
        cout<<"double handled";
    }
}