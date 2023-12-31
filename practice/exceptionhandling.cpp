#include<iostream>
using namespace std;

void divide(double a,double b){
    try{
        if(b==0){
            throw b;
        }
        cout<<a/b<<endl;
    }
    catch(double b){
        cout<<"cant divide by 0";
    }
}
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    divide(a,b);
}