#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class record{
    private:
        string name;
        string DOB;
        long int tele;
        int code;

    public:
    static vector<record>r1;
    static void insert(){
        record obj;
        cout<<"Enter the Name of the Person:";
        cin>>obj.name;
        cout<<"Enter the date of Birth(dd/mm/yyyy):";
        cin>>obj.DOB;
        cout<<"Enter the telephone number:";
        cin>>obj.tele;
        cout<<"Set the code:";
        cin>>obj.code;
        r1.push_back(obj);
    }

    static void print(record r2){
        cout<<"\nName: "<<r2.name;
        cout<<"\nDoB: "<<r2.DOB;
        cout<<"\nTelephone Number: "<<r2.tele;
    }

    static void display(){
        for_each(r1.begin(),r1.end(),print);
    }

    static bool compareCode(record a,  record b){
        return a.code<b.code;
    }

    void search(){
        int search;
        cout<<"Enter the code of the Person to search:";
        cin>>search;

        bool flag=false;
        for(const auto& item:r1){
            if (item.code==search){
                cout<<"\nFound!";
                item.print(item);
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"Person not found in record.";
        }
    }

     void delet(){
        int delcode;
        cout<<"Enter the code of the person to delete:";
        cin>>delcode;

        bool flag=false;
        for (auto it=r1.begin();it!=r1.end();it++){
            if (it->code==delcode){
                r1.erase(it);
                cout<<"Person's record Deleted";
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"Person record not found!";
        }
     }
};
vector<record> record::r1;

int main(){
    record object;
    int ch;
      cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
 
    do{
        cout<<"\nEnter your choice:";
        cin>>ch;
         switch(ch){
        case 1:
             object.insert();
             break;
        case 2:
             object.display();
             break;
        case 3:
             object.search();
             break;
        case 4:
             sort(record::r1.begin(),record::r1.end(),record::compareCode);
             cout<<"\nsorted on code number:";
             record::display();
             break;
        case 5:
             object.delet();
             break;
        case 6:
            cout<<"Exiting program...........";
            break;
        default:
          cout<<"Invalid choice!Please enter valid choice.";
          break;
    }
   
    }while(ch!=6);
    return 0;
}