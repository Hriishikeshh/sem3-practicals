#include<iostream>
using namespace std;

class deque{
    int* arr;
    int front;
    int rear;
    int size;

public:
    deque(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty(){
        return front == -1;
    }

    bool pushFront(int x){
        if(isFull()){
            cout<<"queue is full"<<endl;
            return false;
        }

        if(front == -1){   //empty fill
            rear = front = 0;
        }
        else if(front == 0){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        if(isFull()){
            cout<<"queue is full"<<endl;
            return false;
        }

        if(front == -1){   //empty fill
            front = rear = 0;
        }
        else if(rear == size - 1){  //circular fill
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popRear(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;  //logical deletion

        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size - 1;
        }
        else{
            rear--;
        }

        return ans;
    }

    int popfront(){
        if(isEmpty()){
            cout<<"queue is empty";
            return -1;
        }

        int ans=arr[front];
        arr[front]=-1;

        if(front==rear){
            front=rear=-1;
        }

        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }

        return ans;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        while(i != rear){
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};

int main(){
    deque dq(5);
    dq.pushFront(7);
    dq.pushRear(8);
    dq.display();
    dq.popRear();
    dq.pushRear(10);
    dq.display();
    dq.popfront();
    dq.pushFront(11);
    dq.display();

    return 0;
}

