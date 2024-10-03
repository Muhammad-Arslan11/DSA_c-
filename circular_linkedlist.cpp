

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

// insert 
  void insert(int data, Node* &tail, int element){

        // create a new Node
     Node* newNode = new Node(data);
 
     // if list is empty
    if(tail == NULL){  
       tail = newNode;
     tail->next = tail;
     return;
    
    }
     else{ 
      // assuming that the list is not empty
     // create a new reference
     Node* curr = tail;
     while( curr->data != element){
        curr = curr->next;
     }
        
      
        // Insert newNode after curr
        newNode->next = curr->next;
        curr->next = newNode;

        // Update tail if newNode is inserted at the end
        if (curr == tail){
            tail = newNode;
        }

     
    
    }
    
}
void print(Node* tail){
       if (tail == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while( tail != temp);
  

   cout<<endl;
}

  


int main(){
    Node* tail = NULL;
    //    print(tail);
    // create a node
    Node* node1 = new Node(10);
   tail = node1;
       print(tail);
    insert(20,tail,10);
       print(tail);
        insert(30,tail,20);
        print(tail);
    

    return 0;
}