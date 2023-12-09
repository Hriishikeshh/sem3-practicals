#include<iostream>
using namespace std;

class node{
     public:
        int val;
        node* next;
        node* prev;
        bool isbook;
        node(int val){
            this->val=val;
            next=NULL;
            prev=NULL;
            isbook=false;
        }
};

class Rows{

    public:
    node* head;
    node* tail;

    
        Rows(int size){
            head=NULL;
            tail=NULL;
            for(int i=0;i<size;i++){
                node* new_node=new node(i);

                if(head==NULL){
                    head=new_node;
                    tail=new_node;
                    new_node->next=new_node;
                    new_node->prev=new_node;
                }else{
                    tail->next = new_node;
                    new_node->prev = tail;
                    tail = new_node;
                    tail->next = head;
                    head->prev = tail;
                }
            }
        }

        void display(){
            node* current=head;
            do{
                if(!current->isbook){
                    cout<<"A"<<" ";
                }
                else{
                    cout<<"B"<<" ";
                }
                current=current->next;
            }while(current!=head);
            cout<<endl;
        }

};

class cinemax{
    public:
        Rows* rows[10];

        cinemax(){
            for(int i=0;i<10;i++){
                rows[i]=new Rows(7);
            }
        }

        void display(){
            for(int i=0;i<10;i++){
                cout<<" row number "<<i<<endl;
                rows[i]->display();
            }
        }

        void bookseats(int row, int start, int numseats){
            if(row>=1 && row<=10 && start>=1 && start<=7){
                
                node* current=rows[row]->head;

                //traversal to start seat
                for(int i=1;i<start;i++){
                    current=current->next;
                }

                bool isavailable=true;

                //check if already booked
                for(int i=1;i<numseats;i++){
                    if(current->isbook){
                        isavailable=false;
                        cout<<"seat is booked at "<<i;
                        break;
                    }
                    current=current->next;
                }

                //if available case booking
                if(isavailable){
                    node* current=rows[row]->head;

                    //traversal to start seat
                    for(int i=1;i<start+1;i++){
                        current=current->next;
                    }

                    for(int i=1;i<numseats+1;i++){
                        if(!current->isbook){
                            current->isbook=true;
                        }
                        current=current->next;
                    }
                    cout<<"seat in row  "<<row<<"booked from "<<start<<endl;
                }

                else{
                    cout<<"seats already booked"<<endl;
                }
            }
            else{
                cout<<"invalid values"<<endl;
            }
        }

        //cancelling bookings
        void cancelseats(int row,int start,int numseats){
            if(row>=1 && row<=10 && start>=1 && start<=7){
                    
                    node* current=rows[row]->head;

                    //traversal to start seat
                    for(int i=1;i<start+1;i++){
                        current=current->next;
                    }

                    bool isavailable=true;

                    //check if already booked
                    for(int i=1;i<numseats+1;i++){
                        if(current->isbook){
                            current->isbook=false;
                        }
                        current=current->next;
                    }
                    cout<<"booking for seats from "<<start<<"to"<<start+numseats-1<<"are cancelled"<<endl;
            }
            else{
                cout<<"invalid numbers"<<endl;
            }
        }
};

int main(){
    cinemax seat;
    seat.display();
    seat.bookseats(1,2,4);
    seat.display();
    seat.bookseats(1,2,1); 
    seat.display();
}