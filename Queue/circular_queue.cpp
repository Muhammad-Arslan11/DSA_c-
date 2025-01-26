
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
        this->size = 0;
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

    bool
    isFull()
    {
        return ((rear + 1) % capacity == front);
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
        front = (front + 1) % capacity;
        size--;
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