#include<iostream>
using namespace std;

class complex{
    int real;
    int imag;
    public:
        complex(){
            real=0;
            imag=0;
        }

        //overloading +
        complex operator+(complex a){
            complex add;
            add.imag=a.imag+imag;
            add.real=a.real+real;
            return add;
        }

        //overloading -
        complex operator-(complex m){
            complex minus;
            minus.imag=m.imag-imag;
            minus.real=m.real-real;
            return minus;
        }

        // overloading ++
        complex operator++(complex e){
            complex increment;
            increment.real=e.real++;
            increment.imag=e.imag++;
            return increment;
        }

        //overloading insertion
        friend istream& operator>>(istream& in,complex& t){
            cout<<"enter real part :"<<endl;
            in>>t.real;
            cout<<"enter imaginary part :"<<endl;
            in>>t.imag;
            return in;
        }

        //overloading extraction
        friend ostream& operator<<(ostream& out,complex& p){
            out<<"complex number :"<<p.real<<"+i("<<p.imag<<")"<<endl;
            return out;
        }

};

int main(){
    complex c1,c2,c3,c4,c5;
    cout<<"1st :"<<endl;
    cin>>c1;
    cout<<"2nd :"<<endl;
    cin>>c2;
    c3=c1+c2;
    c4=c1-c2;
    c5=c1+1;

    cout<<"sum:"<<c3;
    cout<<"difference:"<<c4;
    cout<<"increment:"<<c5;

}