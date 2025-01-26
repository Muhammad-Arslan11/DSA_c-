

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
      Node* forward = NULL;

      while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
      }
       prev = head; // update the head
      return head;
 }

int main(){
  Node* head = NULL;

    insert_at_head(1, head);
    insert_at_head(2, head);
    insert_at_head(3, head);
    insert_at_head(4, head);

    cout << "Original list: ";
    print(head); // Print the original list

    reverse(head); // Reverse the list

    cout << "Reversed list: ";
    print(head); // Print the reversed list

    return 0;
}