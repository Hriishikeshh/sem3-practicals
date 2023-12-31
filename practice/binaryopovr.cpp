#include<iostream>
#include<string>
using namespace std;

class addition{
    public:
    string p,q;
        addition(){
            p="/0";
            q="/0";
        }
        addition(string,string);
        addition operator+(addition);
};

addition::addition(string a,string b){
    p=a;
    q=b;
}

addition addition::operator+(addition k){
    addition temp;
    temp.p=p+k.p;
    temp.q=q+k.q;
    return (temp);
}
int main(){
    addition ob1("a","b");
    addition ob2("b","d");
    addition ob3;
    ob3=ob1+ob2;
    cout<<"p sum:"<<ob3.p<<" q :"<<ob3.q;

}