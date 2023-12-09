#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class file{
    ofstream filestr;

    public:
        file(){
            filestr.open("text.txt",ios::app);
        }

        void appendData(string& data){
            filestr<<data<<endl;
        }

        void displaydata(){
            filestr.close();   //closed for opening and writing
            ifstream input("text.txt");
            cout<<"file contents :"<<endl;
            string line;
            while(getline(input,line)){
                cout<<line<<endl;
            }
            input.close();
            filestr.open("text.txt",ios::app);
        }

        ~file(){
            filestr.close();
        }
};

int main(){
    //open write in file

    fstream fout;
    fout.open("text.txt",ios::out);
    string line;

    while(fout){
        getline(cin,line);
        if(line=="-1"){
            break;
        }
        fout<<line<<endl;
    }
    fout.close();

    //appending in file

    char choice;
    while(true){
        cout<<"enter choice to append data(y/n) :";
        cin>>choice;

        if(choice!='y'){
            break;
        }

        file f;
        string data;
        string line;
        cin.ignore();
        cout<<"enter data to append :";
        getline(cin,data);
        f.appendData(data);
        f.displaydata();
    }
}