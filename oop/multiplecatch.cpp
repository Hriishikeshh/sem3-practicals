#include<iostream>
using namespace std;

void number(int data){
    try{
        if(data%2!=0){
            throw "odd number";
        }
        else{
            throw data;
        }
    }
    catch(int i){
        cout<<"integer exception handled thus : even number "<<i<<endl;
    }
    catch(const char *str){
        cout<<"char exception handled thus :"<<str<<endl;
    }
}
int main(){
    number(9);
    number(0);
}