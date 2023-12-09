#include<iostream>
#include<vector>
using namespace std;

class publication{
    public:

        string title;
        float price;

        void input(string title,float price){
            cout<<"enter title :";
            cin>>title;
            cout<<endl;

            cout<<"enter price :";
            cin>>price;
        }        
};

class book:public publication{
    vector<string> book_arr;
    vector<float> price_arr;
    int pages;
    public:
    
        void input(){
            book_arr.push_back(title);
            price_arr.push_back(price);
        } 

        void display(){
            for(auto i=book_arr.begin();i!=book_arr.end();i++){
                cout<<*i<<
            }
        }

};

int main(){
    publication pb;

}