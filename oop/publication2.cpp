#include<iostream>
using namespace std;
class publication{
    public:
    char title[30];
    float price;
};

class book:public publication{
public:
int count;
void getcount(){
    cout<<"Enter the name of the book:";
    cin>>title;
    cout<<"Enter the price:";
    cin>>price;
    cout<<"Enter the page count:";
    cin>>count;
}
void displaycount(){
    cout<<"Name of the book:"<<title<<endl;
    cout<<"    Price:"<<price<<endl;
    cout<<"    Page count:"<<count<<endl;
    }

};
class tape:public publication{
    public:
    int time;
    void gettime(){
        cout<<"Enter the name of the audio:";
        cin>>title;
        cout<<"Enter the price:";
        cin>>price;
        cout<<"Enter the timing of the audio:";
        cin>>time;
    }
    void displaytime(){
    cout<<"Name of the Audio Tape:"<<title<<endl;
    cout<<"     Price:"<<price<<endl;
    cout<<"     Audio Time:"<<time<<"minutes"<<endl;
    }
};

int main(){
    book b;
    tape t;
    b.getcount();
    t.gettime();
    cout<<"__________________Display Data______________________"<<endl;
    b.displaycount();
    t.displaytime();
}
