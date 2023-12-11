#include<iostream>
#include<stdexcept>

using namespace std;

class publication{
    public:
        string title;
        float price;        
};

class book:public publication{
    public:
        int pages;

        void getdata(){
            cout<<"enter title :";
            cin>>title;
            cout<<"enter price :";
            cin>>price;
            cout<<"enter pages :";
            cin>>pages;
        }

        void displaydata(){
            try{
                if(price<0 | pages<0){
                    throw price,pages;
                }
                else{
                    cout<<title<<"  "<<price<<"  "<<pages<<"  "<<endl;
                }
            }
            catch(float x){
                cout<<0<<"  "<<0<<"  "<<0<<endl;
            }
        }
};

class tape:public publication{
    public:
        int time;
        void getdata(){
            cout<<"enter title :";
            cin>>title;
            cout<<"enter price :";
            cin>>price;
            cout<<"enter time(min) :";
            cin>>time;
        }

        void displaydata(){
            try{
                if(price<0|time<0){
                    throw price,time;
                }
                else{
                    cout<<title<<"  "<<price<<"  "<<time<<"  "<<endl;
                }
            }
            catch(float x){
                cout<<0<<"  "<<0<<"  "<<0<<endl;
            }
        }
};

int main(){
    int n;
    cout<<"enter books count :";
    cin>>n;

    book b[n];
    int i,j;

    for(i=0;i<n;i++){
        b[i].getdata();
    }
    
    cout<<"name"<<"  "  <<"price"<<"  "<<"pages"<<endl;
    for(i=0;i<n;i++){
        b[i].displaydata();
    }
    // tape t;
    // t.getdata();
    // t.displaydata();
}
