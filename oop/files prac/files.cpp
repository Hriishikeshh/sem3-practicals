#include<iostream>
#include<fstream>
using namespace std;

class file{
    public:
        ofstream fobj;

        file(){
            fobj.open("sample.txt",ios::app);
        }

        void appendData(string& data){
            fobj<<data<<endl;
        }

        void displaydata(){
            fobj.close();
            ifstream ifobj;
            ifobj.open("sample.txt");
            
            cout<<"file data :"<<endl;

            string line;
            while(getline(ifobj,line)){
                cout<<line<<endl;
            }
            ifobj.close();
            fobj.open("sample.txt",ios::app);
        }
};

int main(){

    //create and write in file
    fstream fout;
    fout.open("sample.txt",ios::out);

    string line;
    while(fout){
        getline(cin,line);
        if(line=="-1"){
            break;
        }
        fout<<line<<endl;
    }
    fout.close();

    //append in file

    char choice;
    while(true){
        cout<<"wanna append(y/n)? :";
        cin>>choice;
        if(choice!='y'){
            break;
        }

        file f;
        string data;
        cin.ignore();
        cout<<"enter data to append:";
        getline(cin,data);
        f.appendData(data);
        f.displaydata();
    }
}