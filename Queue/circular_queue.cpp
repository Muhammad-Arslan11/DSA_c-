
#include <iostream>
using namespace std;

// class Queue
class CircularQueue
{
    int front, rear, size, capacity;
    int *array; // dynamic array

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        this->front = 0;
        this->size = 0;  // size hamain btai ga k iss main kitne elements majood hn
        this->rear = -1;
        array = new int[this->capacity];
    }

    // Destructor to free allocated memory
    ~CircularQueue()
    {
        delete[] array;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    bool isFull()
    {
        return size == capacity;
    }
    

    bool isEmpty()
    {
        return size == 0;
;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        // note: iss chez ka hamasha khayal rakhna ha k rear -1 se start hota h, to jab bhi element 
        // insert krna hoto rear+1 kar k phir arr[rear] ki jaga element insert krna chiye 
        rear = (rear + 1) % capacity;
        array[rear] = data;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // note: enqueue k waqt rear ko ek step agay kreinga aur dequeue k waqt front ko ek step agay krainga
        front = (front + 1) % capacity;
        size--;
        
        if (size == 0) // Reset to initial state if only one element was there
        {
            front = 0;
            rear = -1;
        }
    }
    
};

int main()
{
    CircularQueue q(1000);
    for (int i = 1; i <= 10; i++)
    {
        q.enqueue(i);
    }

    q.printQueue();

    q.dequeue();
    q.printQueue();

    return 0;
}