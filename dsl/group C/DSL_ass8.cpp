#include<iostream>
#include<string>
using namespace std;

class node{
     public:
        string data;
        node* next;
}*headA,*headV,*headB,*Head;

node* create(node*head,int c){
    node*Newnode;
    node* p;
    for (int i=0;i<c;i++){
        Newnode=new node;
        cout<<"Enter the name:";
        cin>>Newnode->data;
        Newnode->next=NULL;
       if (head==NULL){
            head=Newnode;
            p=head;
        }
        else{
            p->next=Newnode;
            p=p->next;
        }
        }
    return head;
}
void display(node*head){
    node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
node* intersection(node* headi) {
    node *p = headB, *q, *newnode, *temp;
    while (p != NULL) {
        q = headV;
        while (q != NULL) {
            if (p->data == q->data) {
                newnode = new node;
                newnode->data = p->data;
                newnode->next = NULL;
                if (headi == NULL) {
                    headi = newnode;
                    temp = headi;
                } else {
                    temp->next = newnode;
                    temp = temp->next;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
    return headi;
}
//Students who like either of icecreams or not both
void func() {
    node* p, * q;
    int flag = 0;
    p = headA;
    while (p != NULL) {
        flag = 0;
        q = Head;
        while (q != NULL) {
            if (p->data == q->data) {
                flag = 1;
                break; 
            }
            q = q->next;
        }
        if (flag == 0) {          
            cout<<p->data<<" ";
            }
        p = p->next;
    } 
}
void neither() {
    node* p = headB;
    node* q;
    node*r,*s,*t;
    int count,count1,count2,count3;
    while (p != NULL) {
        q = headV;
        while (q != NULL) {
            if (p->data == q->data) {
               count++;
            }
            q = q->next;
        }
        p = p->next;
    }
    r=headA;
    while(r!=NULL){
      count1++;
      r=r->next;
    }
     p=headB;
    while(p!=NULL){
      count2++;
    p=p->next;
    }
     q=headV;
    while(q!=NULL){
      count3++;
      q=q->next;
    }
    int Num=(count1-((count2+count3)-count));
    cout << Num;
}
int main(){
    headA=headV=headB=Head=NULL;
    cout<<"\n\nSet of all students:"<<endl;
    int c1;
    cout<<"Enter Number of Students:";
    cin>>c1;
    headA=create(headA,c1);
    display(headA);

    cout<<"\n\nStudents who like buttrescotch icecream:"<<endl;
    int c2;
    cout<<"Enter Number of Student who like Butterscotch:";
    cin>>c2;
    headB=create(headB,c2);
    display(headB);

    cout<<"\n\nStudents who like Vanilla icecream;"<<endl;
    int c3;
    cout<<"Enter Number of Student who like Vanilla:";
    cin>>c3;
   headV=create(headV,c3);
   display(headV);
   cout<<"\n\nSet of intersection:"<<endl;
   Head=intersection(Head);
   display(Head);
   cout<<"\n\nSet of either of two or not both:";
   func();
   cout<<"\nNumber of students who like neither Vanilla nor Butterscotch:";
   neither();
return 0;
}
