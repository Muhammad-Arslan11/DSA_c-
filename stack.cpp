
#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> myStack){
    while(!myStack.empty()){
  // print the content of myStack untill it is empty
    cout<< myStack.top()<<" ";
    myStack.pop();
    
    }
    cout<<endl;
}

int main(){

    // create stack
    stack<int> myStack;
    stack<int> myStack1;

    // populate myStack1
    myStack1.push(4);
       myStack1.push(5);
          myStack1.push(6);
 // perform push, pop, empty, and peek operations in myStack
    myStack.push(1); // push
     myStack.push(2);
      myStack.push(3);
    myStack.pop(); // pop: this will remove the last element in the stack
    myStack.top(); // returns the top element in the stack
    myStack.empty(); // returns bool.
    myStack.size(); // returns the size of the stack
    // myStack.swap(myStack1); // replaces the content of  one stack with the other 
    // myStack.emplace();

     printStack(myStack);
    //  printStack(myStack1);
    cout<< myStack.empty()<<endl; // true

    return 0;
}