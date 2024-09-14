

#include<iostream>
#include<list>
using namespace std;

// Node class
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete this->next;
            this->next = NULL;
        }
        cout<<this->data<<": free"<<endl;
    }
};
 // print 
//  void print(Node* &tail){
//     while(tail != NULL)
//  }
// insert 
  void insert(int data, Node* tail){
    // create a new Node
     Node* newNode = new Node(data);
     // create a pointer for reference
     Node* temp = tail;

     if(tail->next == NULL){
     tail->next = tail;

     }
     else if(tail-){
        // create a pointer to hold the reference of tail->next
        Node* forward = tail->next;
        temp->next = newNode;
        newNode->next = forward;
        tail = newNode; // update tail
     }
     cout<<"data "<<newNode->data<<" next "<<newNode->next;
    cout<<endl;

  }
  


int main(){
    // crreate a node
    Node* node1 = new Node(10);
    Node* tail = node1;
    insert(20,tail);
        insert(30,tail);
    

    return 0;
}