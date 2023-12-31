#include<iostream>
using namespace std;

class numbers{
    public:
        int a,b;

        int values(int p,int q){
            a=p;
            b=q;
        }
};
class value1:public numbers{
    public:
        int value(){
            return a;
        }
};
class value2:public numbers{
    public:
        int value(){
            return b;
        }
};

int main(){
    value1 v1;
    value2 v2;

    numbers* n1=&v1;
    numbers* n2=&v2;
    n1->values(1,2);
    n2->values(1,2);
    cout<<v1.value()<<endl;
    cout<<v2.value();
}