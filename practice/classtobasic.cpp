#include<iostream>
using namespace std;

class basic{
    public:
        operator int();
};
basic::operator int(){
    int sum=9;
    return sum;
}
int main(){
    int a;
    a=23;
    cout<<a<<endl;
    basic obj;
    a=int(obj);
    cout<<a;
}