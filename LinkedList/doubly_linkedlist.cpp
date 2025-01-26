

#include <iostream>
#include <list>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  Node(int d)
  {
    this->data = d;
    this->next = NULL;
    this->prev = NULL;
  }
  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete this->next;
      this->next = NULL;
      delete this->prev;
      this->prev = NULL;
    }
    cout << this->data << ": free" << endl;
  }
};



// print function
void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " "; // print data
    temp = temp->next;         // increment pointer
  }
  cout<<endl;
}

// insert at head
void insert_at_head(int data, Node *&head, Node *&tail)
{
  // create new node
  Node *temp = new Node(data);

  if (tail == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    temp->next = head; // point temp to head
    head->prev = temp; // point head's prev pointer to temp
    // temp->prev = NULL;
    head = temp; // head moves to temp
  }
}

// insert at tail
void insert_at_tail(int data, Node *&head, Node *&tail)
{
  // create new node
  Node *temp = new Node(data);
  if (tail == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    temp->prev = tail; // point temp's prev to tail
    tail->next = temp; // point tail's next pointer to temp
    // temp->next = NULL;
    tail = temp; // head moves to temp
  }
}

// insert at position
void insert_at_position(int data, int pos, Node *&head)
{
  if (pos <= 0)
  {
    return;
  }

  // create a new pointer
  Node *temp = head;

  // travers
  int count = 1;
  while (count < pos - 1)
  {
    temp = temp->next;
    count++;
  }
  // create a new node
  Node *newNode = new Node(data);
  newNode->next = temp->next;
  newNode->prev = temp;
  newNode->next->prev = newNode;
  temp->next = newNode;
}

// deletion
void delete_node(int pos, Node *&head)
{
  Node *prev = head;
  Node *current = head;

  if (pos == 1)
  {
    // if pos is actually the head
    head = head->next;
    delete prev;
  }
  else
  {
    // if pos is either any number in-between head and tail or it is the tail
    int count = 1;
    while (count <= pos - 1)
    {
      prev = current;          // now, prev is actually the current
      current = current->next; // here, current changes its location
      count++;
    }
    // at this line, current is located at the right given position
    prev->next = current->next;
    current->next->prev = prev;
    current->next = NULL;
    current->prev - NULL;
    delete current;
  }
}

int main()
{
  // create a Node
  Node *node1 = new Node(10);
  Node *head = node1;
  Node *tail = node1;

  insert_at_head(12, head, tail);
  print(head);

  insert_at_head(14, head, tail);
  print(head);

  insert_at_tail(15, head, tail);
  print(head);
  insert_at_position(20, 3, head);
  print(head);
  delete_node(3,head);

  return 0;
}