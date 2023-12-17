//Program:
//============================================================================
// Name        : OOPCGL_Assignment2_21159.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;
class student_data;
class student{
  long long int tel_no;
  long long int drvlic_no;
	
	int roll_no;
    string div;
	string name;
	string blood_grp;
	string cls;
	string dob;
	
public:
//Default constructor
	student(){
		roll_no = 0;
		name="";
		div = "";
		blood_grp ="";
		cls="";
		//cout<<"Default constructor is called."<<endl;

	}
	//Parameterised costructor
	student(int r,string n,string c,string d,string b,string dob){
		this->roll_no=r;
		this->name=n;
		this->cls=c;
		this->div=d;
        this->blood_grp=b;
		this->dob=dob;
		cout<<"Parameterised constructor is called!!!"<<endl;
	}
	void getdata(){
		cout<<"\nEnter the name of the student:";
		cin>>name;
		cout<<"Enter the roll number: ";
		cin>>roll_no;
		cout<<"Enter student class: ";
		cin>>cls;
		cout<<"Enter the division: ";
		cin>>div;
        cout<<"Enter the blood group: ";
		cin>>blood_grp;
		cout<<"Enter the date of birth: ";
		cin>>dob;
		

	}
	void displaydata(){
		cout<<name<<"\t";
		cout<<cls<<"\t";
		cout<<div<<"\t";
		cout<<roll_no<<"\t";
		cout<<blood_grp<<"\t";
		cout<<dob<<"\t";
	
	}
	friend class student_data;
	//Destructor
	~student(){
		cout<<"Destructor is called";
	}
};

class student_data{
	static int count;
	string con_add;
    student*dat;

public:
student_data(){
    dat=new student;//Use of new operator
}
student_data(long int t,long int d,string c){
	dat=new student;
   this->dat->tel_no=t;
   this->dat->drvlic_no=d;
   this->con_add=c;
}
	student_data(student_data * s){
		cout<<"Copy contsructor is called"<<endl;
		dat->tel_no=s->dat->tel_no;        
		dat->drvlic_no=s->dat->drvlic_no;   
		con_add=s->con_add; 
		cout<<dat->tel_no; 
		cout<<dat->drvlic_no;
		cout<<con_add;     
		
		}
	void readdata(){
	    cout<<"Enter the contact address: "<<"\t";
		cin>>con_add;
		cout<<"Enter the telephone number: "<<"\t";
		cin>>dat->tel_no;
	
		}
		inline void data(){
        cout<<"Enter the driving license number: "<<"\t";
		cin>>dat->drvlic_no;
	  
		}
    void outdata(){
		cout<<con_add<<"\t";
		cout<<"\t"<<dat->tel_no;
		cout<<"\t"<<dat->drvlic_no<<endl;
		
		
	}
	static void showcount() //Static member function
    {
		cout<<"\nNo of records count="<<count<<"\n";
    }
		
};
int student_data::count;
int main() {
	int ch;
cout<<"Parameterised constructor is called.";
cout<<"=========================================================================="<<endl;
cout<<"name";	
cout<<"\tClass";
cout<<"\tDivision";
cout<<"Rollno";
cout<<"\tBlood";
cout<<"\tDOB";
cout<<"\t\taddress";
cout<<"\t\ttel_no";
cout<<"\tLicense";
cout<<endl;

//display parameterised constructor data
student s(1234,"Name","SE","1","B","dd/mm/yyyy");//Parametrised constructor is called
student_data t(9100,120,"Address");//Parameterised constructor
s.displaydata();
t.outdata();

//copy constructor data
cout<<"Copy constructor is called.: ";
student_data x(t);//copy constructor
x.outdata();
cout<<endl;

//dynamic
int n;
cout<<"\nEnter how many records you want??";
cin>>n;
student p3[n]; //array of object
student_data p4[n];
int z=0;
int y=0;
do
{
cout<<"\n               Welcome to Srudent Database System                        ";
cout<<"\n1.Enter the record";
cout<<"\n2.Display the record";
cout<<"\n3.Exit";
cin>>ch;
switch(ch)
{
case 1:
{

p3[z].getdata();
p4[y].readdata();
p4[y].data();
student_data::showcount(); // calls static function
z++;
y++;
break;
}
case 2:
{cout<<"name";	
cout<<"\tClass";
cout<<"\tDivision";
cout<<"\tRollno";
cout<<"\tBloodgroup";
cout<<"\tDOB";
cout<<"\taddress";
cout<<"\ttel_no";
cout<<"\tLicense";

for(int i=0;i<n;i++)
{
cout<<"\n";
p3[i].displaydata();
p4[i].outdata(); 
}
break;
}
}
}while(ch!=3);	

return 0;
}
