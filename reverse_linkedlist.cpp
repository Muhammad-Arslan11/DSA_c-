

#include<iostream>
#include<list>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
      this->data = data;
      this->next = NULL;
    }

};

// function to print the node data
 void print(Node* &head){
    // create a temporary pointer
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" "; // print data
        temp = temp->next; // increment pointer
    }
    cout<<endl;
 }

// function to insert node at head
 void insert_at_head(int data, Node* &head){
        // create a new Node
        Node *newNode = new Node(data);
        newNode -> next = head;  // head->next = newNode;
        head = newNode;  // newNode->next = NULL;
       
 }

 Node* reverse(Node* &head){
      Node* prev = NULL;
      Node* curr = head;
      Node* forward = curr->next;

      while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
      }

      return prev;
 }

int main(){
   // create a node
    Node* node1 = new Node(10);
    // here, both the head and the tail refer to the same n
    Node* head = node1;

    insert_at_head(20,head);
      insert_at_head(30,head);
        insert_at_head(40,head);

        // reverse(head);

     // print 
     print(head);

     

    return 0;
}