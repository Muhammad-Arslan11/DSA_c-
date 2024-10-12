 /* 
   stack class implementation using arrays
   two stack implementation in an array
 */
#include<iostream>
using namespace std;

class Stack {
    int top1;
    int top2;
    int size;
    int* arr;

public:
    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push in stack1
    void push1(int n) {
        if (top1 + 1 == top2) {  // Check if there's space for stack1
            cout << "Stack overflow in stack1" << endl;
        } else {
            top1++;
            arr[top1] = n;
        }
    }

    // Push in stack2
    void push2(int n) {
        if (top2 - 1 == top1) {  // Check if there's space for stack2
            cout << "Stack overflow in stack2" << endl;
        } else {
            top2--;
            arr[top2] = n;
        }
    }

    // Pop from stack1
    void pop1() {
        if (top1 >= 0) {
            cout << "Popped from stack1: " << arr[top1] << endl;
            top1--;
        } else {
            cout << "Stack underflow in stack1" << endl;
        }
    }

    // Pop from stack2
    void pop2() {
        if (top2 < size) {
            cout << "Popped from stack2: " << arr[top2] << endl;
            top2++;
        } else {
            cout << "Stack underflow in stack2" << endl;
        }
    }

    // Print the contents of stack1
    void printStack1() {
        if (top1 >= 0) {
            cout << "Stack1 elements: ";
            for (int i = top1; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack1 is empty" << endl;
        }
    }

    // Print the contents of stack2
    void printStack2() {
        if (top2 < size) {
            cout << "Stack2 elements: ";
            for (int i = top2; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack2 is empty" << endl;
        }
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }
};

  int main(){
    // initialize stack
    Stack myStack = Stack(10);
    // myStack.push(1);
    // cout<< myStack.peek()<<endl;
    // cout<< myStack.isEmpty()<<endl;
    // myStack.pop();
    // cout<< myStack.isEmpty()<<endl;
    // myStack.pop();


     myStack.printStack1();
     myStack.push1(1);

     myStack.push2(2);
     myStack.push1(3);
     myStack.push2(4);
       myStack.printStack1();
         myStack.printStack2();

         myStack.pop1();
         myStack.pop2();
           myStack.printStack1();
            myStack.printStack2();




    



    return 0;
  }