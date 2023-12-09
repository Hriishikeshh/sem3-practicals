#include<iostream>
using namespace std;

class node{
    public:
        int val;
        bool isbooked;
        node* next;

        node(int val){
            this->val=val;
            isbooked=false;
            next=NULL;
        }
};


class Rows{
    public:

        node* head;
        node* tail;

        Rows(int numseats){
            head=NULL;
            tail=NULL;

            for(int i=0;i<numseats;i++){
                node* new_node=new node(i);

                if(head==NULL){
                    head=new_node;
                    tail=new_node;
                    new_node->next=new_node;
                }else{
                    tail->next=new_node;
                    tail=new_node;
                    tail->next=head;
                }
            }
        }

        void display(){
            node* current=head;
            do{
                if(!current->isbooked){
                    cout<<'A'<<" ";
                }else{
                    cout<<'B'<<" ";
                }
                current=current->next;
            }while(current!=head);
            cout<<endl;
        }
};

class theatre{
    public:
        Rows* rows[10];

        theatre(){
            for(int i=1;i<=10;i++){
                rows[i]=new Rows(7);
            }
        }

        void display(){
            for(int i=1;i<=10;i++){
                cout << "Available seats in Row " << i << ":\n";
                rows[i]->display();
            }
        }

        void bookseats(int row,int start,int numSeats){
            if(row>=1 && row<=10 && start>=1 && start<=7){

                //checks whether seats are already booked
                node* current=rows[row]->head;

                for(int i=1;i<=start;i++){     //travel to req position
                    current=current->next;
                }

                bool seatisavailable = true;   //boolean flag

                for(int i=1;i<=start;i++){         //check if booked
                    if(current->isbooked){
                        seatisavailable=false;
                        break;
                    }
                    current=current->next;
                }

                //if not booked then books here
                if(seatisavailable){                   //book if not booked
                    node* current=rows[row]->head;

                    for(int i=1;i<=start;i++){
                        current=current->next;
                    }

                    for(int i=1;i<=numSeats;i++){
                        if(!current->isbooked){
                            current->isbooked=true;
                        }
                        current=current->next;
                    }
                cout<<"seat in row "<<row<<" from "<<start<<" are booked "<<endl;
                }

                else{
                    cout<<"required seats aare already booked"<<endl;
                }
            }
            else{
            cout<<"invalid numbers"<<endl;
            }
        }

        void cancelseats(int row,int start,int numSeats){
            if(row>=1 && row<=10 && start>=1 && start<=7){
                node* current=rows[row]->head;

                for(int i=1;i<=start;i++){
                    current=current->next;
                }

                for(int i=1;i<=numSeats;i++){
                    if(current->isbooked){
                        current->isbooked=false;
                    }
                    current=current->next;
                }

            cout<<"seat in row "<<row<<" from "<<start<<" to "<<start+numSeats-1<<" bookings are cancelled "<<endl;
            }
            else{
                cout<<"invalid numbers"<<endl;
            }
        }



};

int main(){
    theatre cinemax;
    cinemax.display();

    do{

        int choice;
        cout<<"menu: \n 1.show available seats \n 2.book seats \n 3.cancel booking \n 4.exit "<<endl;
        cin>>choice;

        if(choice==1){
            cinemax.display();
        }

        else if(choice==2){
            int row,start,numseats;
            cout << "Enter the row, starting seat number, and number of seats to book: ";
            cin >> row >> start >> numseats;
            cinemax.bookseats(row, start, numseats);
        }

        else if(choice==3){
            int crow,cstart,cnumseats;
            cout << "Enter the row, starting seat number, and number of seats to cancel booking: ";
            cin >> crow >> cstart >> cnumseats;
            cinemax.cancelseats(crow,cstart,cnumseats);
        }

        else if(choice==4){
            break;
        }
    }while(true);
}
