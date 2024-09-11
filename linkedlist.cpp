

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
        cout<<"memory free"<<endl;
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

 // insert at Tail
  void insert_at_tail(int data, Node* &tail){
       // create a new node
       Node* newNode = new Node(data);
       // set tail's pointer to the newly created node
          tail-> next  = newNode;
         tail = newNode ; // at this line, newNode becomes the tail
         
  }

  // insert at position 
   void insert_at_position(Node* &head,int pos, int d){
      if(pos <= 0){
        return;
    }
      Node* temp = head;
      int count = 1;

      while(count < pos-1 && temp != NULL){
         temp = temp-> next;
         count++;

      }
      if(temp == NULL){
        return;
      }
      // create a new node
       Node* nodeToInsert = new Node(d);
       // change the pointers
       nodeToInsert->next = temp->next; // First, point the pointer of nodeToinsert towards the pointer of temp's pointer 
       temp->next = nodeToInsert; // second, change the temp's pointer to nodeToinsert
       
   }
   void delete_node(int pos,Node* &head){
    Node* temp = head;
    coutn
    if(pos == 1){
    // if pos is actually the head
     head = head->next;
     delete temp;
    }
    else{
        // if pos is either any number in-between head and tail or it is the tail

    }
    int count = 0;
   
    
      // rerefering temp pointer to the pointer of position
       temp->next = pos->next;
      head
   }



int main(){
    // create a node
    Node* node1 = new Node(10);
    // here, both the head and the tail refer to the same node
    Node* tail = node1;
    Node* head = node1;

    
    insert_at_head(12,head); // insert at head
     insert_at_tail(15,tail);  // insert at tail
     insert_at_position(head,2,13); // insert at position
    //   insert_at_tail(15,tail);

     // print 
     print(head);

    
    return 0;
}