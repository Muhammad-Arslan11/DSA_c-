
#include<iostream>
using namespace std;

// class Queue
class Queue{
    int front, rear, size;
    int capacity;
    int* array; // dynamic array

    public:
    Queue(int capacity){
        this->capacity = capacity;
        this->front = 0;
        this->rear = -1;
        array = new int[this->capacity];
    }

    ~Queue() {
        delete[] array;
    }

    void printQueue(){
         for(int i=front; i<=rear; i++){
             cout<<array[i]<<" ";
         }
         cout<<endl;
    }

    bool isFull(){
            return (rear == capacity-1);
    }

    bool isEmpty(){
        return (front == rear+1);
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        array[++rear] = data;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=front; i<rear; i++){
            array[i] = array[i+1]; // shift elements from i to i+1
        }
        rear--;
    }

    // void peek(){
    //     if(isEmpty()){
    //    cout<<"Queue is empty"<<endl;
    //     }
    //     else{
    //     cout<<array[rear];
    //     }
    // }
};


int main(){
    Queue q(10);
    for(int i=1; i<=10; i++){
        q.enqueue(i);
    }

    q.printQueue();

    q.dequeue();
    q.printQueue();
    // q.peek();

    return 0;
}