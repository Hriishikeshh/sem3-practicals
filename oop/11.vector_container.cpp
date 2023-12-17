#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Record{
    string name;
    string dob;
    long long tele;
    int code;

    public:
        static vector<Record>r1;

        void insert(){
            cout<<"enter name:";
            cin>>name;
            cout<<"enter dob:";
            cin>>dob;
            cout<<"enter telephone:";
            cin>>tele;
            cout<<"enter code:";
            cin>>code;
            r1.push_back(*this);
        }

        static void print(const Record& r2){
            cout<<"name :"<<r2.name;
            cout<<"dob :"<<r2.dob;
            cout<<"tele no. :"<<r2.tele;
            cout<<"code no. :"<<r2.code;
        }

        static void display(){
            for_each(r1.begin(),r1.end(),print);
        }

        static bool compareCode(const Record& a,const Record& b){
            return a.code<b.code;
        }


        vector<Record> Record::r1;
        void search(){
            int n;
            cout<<"enter code to search and get data:";
            cin>>n;

            bool flag=false;
            for(const auto& item:r1){
                if(item.code==n){
                    cout<<"found!";
                    print(item);
                    flag=true;
                    break;
                }

            }
            if(!flag){
                cout<<"not found"<<endl;
            }
        }
};

int main(){
    Record obj;
    do{
        int choice;
        cout<<"..menu..\n1.insert\n2.display\n3.search\n4.sort";
        cin>>choice;
        if(choice==1){
            obj.insert();
        }
        else if(choice==2){
            obj.display();
        }
        else if(choice==3){
            obj.search();
        }
        else if(choice==4){
            sort(Record::r1.begin(),Record::r1.end(),Record::compareCode);
            cout<<"sorted on code number:"<<endl;
            obj.display();
            break;
        }
        else{
            break;
        }
    }while(true);
}