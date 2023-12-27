#include<iostream>
#include<string>
using namespace std;

class Jobs{
    string* arr;
    int size;
    int front;
    int rear;

    public:
        Jobs(int size){
            this->size=size;
            arr=new string[size];
            front=0;
            rear=0;
        }

        void enqueue(string data){
            if(rear==size){
                cout<<"queue is full"<<endl;
                return;
            }
            else{
                arr[rear]=data;
                cout<<"added "<<data<<endl;
                rear++;
            }
        }

        string dequeue(){
            if(front==rear){
                cout<<"queue is empty";
            }
            else{
                string ans=arr[front];
                arr[front]=-1;
                front++;
                if(front==rear){
                    front=0;
                    rear=0;
                }
                return ans;
            }
        }

        void display(){
            cout<<"queue :";
            for(int i=front;i!=rear;i++){
                cout<<" ";
                cout<<arr[i];
            }
            cout<<endl;
        }
};

int main(){
    Jobs j(3);
    j.enqueue("peon");
    j.enqueue("manager");
    j.enqueue("intern");
    j.enqueue("intern");
}