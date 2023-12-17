#include<iostream>
using namespace std;

class complex{
    public:
        int real;
        int imag;

        complex(){
            real=0;
            imag=0;
        }

        complex operator+ (complex a){
            complex add;
            add.real=a.real+real;
            add.imag=a.imag+imag;
            return add;
        }

        complex operator- (complex m){
            complex minus;
            minus.real=m.real-real;
            minus.imag=m.imag-imag;
            return minus;
        }

        friend istream& operator>>(istream& in,complex& t){
            cout<<"enter real part :";
            in>>t.real;
            cout<<"enter imaginary part:";
            in>>t.imag;
            return in;
        }

        friend ostream& operator<<(ostream& out,complex& p){
            out<<"complex number :"<<p.real<<"+i("<<p.imag<<")"<<endl;
        }
};

int main(){
    complex c1,c2,c3,c4;
    cout<<"enter 1st number:";
    cin>>c1;
    cout<<"enter 2nd numbe :";
    cin>>c2;

    c3=c1+c2;
    c4=c1-c2;

    cout<<"sum :"<<c3<<endl;
    cout<<"difference :"<<c4;
}