

#include<iostream>
#include<list>
using namespace std;

class Node{
     public:
     int data;
     Node* prev;
     Node* next;

     Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
     }
};

 // print function 
  void print(Node* &head){
    Node* temp = head;
 
    while(temp != NULL){
        cout<<temp->data<<" "; // print data
        temp = temp->next; // increment pointer
    }
  }

// insert at head
 void insert_at_head(int data, Node* &head, Node* &tail){
      // create new node
      Node* temp = new Node(data);
      
       if (tail == NULL) {
        head = temp;
        tail = temp;
    } else{
      temp->next = head; // point temp to head
      head->prev = temp; // point head's prev pointer to temp
      // temp->prev = NULL;
      head = temp;  // head moves to temp
    }
    
 }

 // insert at tail
 void insert_at_tail(int data, Node* &head, Node* &tail){
      // create new node
      Node* temp = new Node(data);
     if (tail == NULL) {
        head = temp;
        tail = temp;
    } else{
      temp->prev = tail; // point temp's prev to tail
      tail->next = temp; // point tail's next pointer to temp
      // temp->next = NULL;
      tail = temp;  // head moves to temp

    }
 }



int main(){
    // create a Node
     Node* node1 = new Node(10);
     Node* head =  node1;
     Node* tail = node1;

     insert_at_head(12,head,tail);
      
     insert_at_head(14,head,tail);
   
       insert_at_tail(15,head,tail);
          
        print(head);
    //  print(tail);

    return 0;
}