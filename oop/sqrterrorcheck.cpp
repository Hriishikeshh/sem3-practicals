#include<iostream>
#include<math.h>
using namespace std;

void sqroot(int data){
    try{
        if(data<0){
            throw " is negative";
        }
        else{
            cout<<"square root is :"<<sqrt(data)<<endl;
        }
    }
    catch(const char *str){
        cout<<"cant handle this shit as "<<data<<str<<endl;
    }
}
int main(){
    sqroot(-12);
    sqroot(75);
}