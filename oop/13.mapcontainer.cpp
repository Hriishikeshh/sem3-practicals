#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    map<string,int>m;
    int num;
    cout<<"enter number of states:";
    cin>>num;
    for(int i=0;i<num;i++){
        string name;
        cout<<"enter state :";
        cin>>name;
        int count;
        cout<<"enter population :";
        cin>>count;
        m.insert({name,count});
    }

    string s;
    cout<<"enter state to get pop :";
    cin>>s;
    map<string,int>::iterator it=m.begin();
    it=m.find(s);
    if(it!=m.end()){
        cout<<"state "<<it->first<<"pop "<<it->second<<endl;
    }
    else{
        cout<<"state absent";
    }

}