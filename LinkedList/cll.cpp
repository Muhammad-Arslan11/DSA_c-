

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(NULL) {}

    ~Node() {
        cout << this->data << ": free" << endl;
        // Avoid deleting the whole list from a single node destructor
    }
};

// Insert function
void insert(int data, Node*& tail, int element) {
    Node* newNode = new Node(data);

    if (tail == NULL) {  
        tail = newNode;
        tail->next = tail; // Circular reference
        return;
    } else {
        Node* curr = tail;
        while (curr->next != tail && curr->data != element) {
            curr = curr->next;
        }

        if (curr->data != element) {
            // Element not found
            delete newNode;
            cout << "Element not found. Insert failed." << endl;
            return;
        }

        // Insert newNode after curr
        newNode->next = curr->next;
        curr->next = newNode;

        // Update tail if newNode is inserted at the end
        if (curr == tail) {
            tail = newNode;
        }
    }
}

// Print function
void print(Node* tail) {
    if (tail == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    
    cout << endl;
}

// Function to delete all nodes
void deleteList(Node*& tail) {
    if (tail == NULL) return;
    
    Node* current = tail;
    Node* nextNode = NULL;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != tail);
    
    tail = NULL; // Set tail to NULL after deletion
}

int main() {
    Node* tail = NULL;

    // Create nodes and print list
    Node* node1 = new Node(10);
    tail = node1;
    tail->next = tail; // Circular reference
    print(tail);

    insert(20, tail, 10);
    print(tail);

    insert(30, tail, 20);
    print(tail);

    // Clean up
    deleteList(tail);

    return 0;

}