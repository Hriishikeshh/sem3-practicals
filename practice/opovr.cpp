#include<iostream>
using namespace std;

class increment{
    public:
        int i;
        increment(int i){
            this->i=i;
        }

        increment& operator++(){
            ++i;
            return *this;
        }

        void display(){
            cout<<" after :"<<i<<endl;
        }

};

int main(){
    increment i1(3);
    cout<<" before : 3";
    increment i2 = ++i1;
    i2.display();
}