#include<iostream>
#include<string>
using namespace std;

template<class T>
#define m 10

class Item{
    T id;
    int priority;

    public:
        void input(){
            cout<<"enter Id :";
            cin>>id;

            cout<<"enter priority :";
            cin>>priority;
        }

        bool operator <= (Item x){
            if(x.priority <= priority){
                return 1;
            }
            else{
                return 0;
            }
        }

        friend class priority_queue;  //access data in Item
};

class priority_queue{
    Item<string> arr[m];
    int front;
    int rear;

    public:
        priority_queue(){   //initialize front and rear
            front=-1;
            rear=-1;
        }
        
        //add item to queue according to priority
        void enqueue(Item<string> data){

            if(front==m-1){
                cout<<"queue is full"<<endl;
                return;
            }

            else if(front==-1 || front==rear+1){   //empty queue
                rear=0;
                front=0;
                arr[rear].id=data.id;
                arr[rear].priority=data.priority;
            }

            else{
                rear++;
                int j=rear-1;
                while(arr[j]<=data && j>=0){    //automatically checking priority value due to bool operator overloaded function
                    arr[j+1]=arr[j];
                    j--;
                }
                arr[j+1].id=data.id;
                arr[j+1].priority=data.priority;
            }

        }

        //displaying id according to priority
        void display(){
            int i=front;
            cout<<"id :"<<arr[i].id<<" priority :"<<arr[i].priority<<endl;
        }

        //deleting the highest priority element from queue
        void dequeue(){
            if(front==-1 || front==rear+1){
                return;
            }

            else{
                front++;
            }
        }

};

int main(){
    priority_queue pq;
    Item<string>it;

    for(int i=0;i<3;i++){
        it.input();
        pq.enqueue(it);
    }

    pq.display();
}


