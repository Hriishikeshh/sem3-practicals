#include<iostream>
using namespace std;

class publication{
    public:
        virtual void display()=0;
};

class book:public publication{
    public:
        string books;
        string read(string bookv){
            books=bookv;
            return books;
        }
        void display(){
            cout<<books<<endl;
        }
};

class tape:public publication{
    public:
        string tapes;
        string read(string tapev){
            tapes=tapev;
            return tapev;
        }
        void display(){
            cout<<tapes;
        }
};

int main(){
    book b;
    tape t;

    publication* p;
    b.read("ramayana");
    p=&b;
    p->display();

    t.read("cassete");
    p=&t;
    p->display();
}