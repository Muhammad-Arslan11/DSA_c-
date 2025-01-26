
#include <iostream>
#include <queue>
using namespace std;

// tree
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *treebuilder(Node *root)
{
  int data;
  cout << "enter the data" << endl;
  cin >> data;
  root = new Node(data);

  if (data == -1)
  {
    return NULL;
  }

  cout << "enter the data for left node: " << data << endl;
  root->left = treebuilder(root->left); //  left branch
  cout << "enter the data for right node: " << data << endl;
  root->right = treebuilder(root->right); //  right branch

  return root;
}

// level order traversal: it travels from level to level                   
void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
   
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
       cout << temp->data << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

void buildFromLevel(Node* &root){
  queue<Node*> q;
  // create node from data
  cout<<"Enter the data for node: "<<endl;
  int data;
  cin>> data;
  root = new Node(data);
  q.push(root);

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    cout<<"enter the data for left node: "<<endl;
    int data;
    cin>> data;
    if(data != -1){
      // create a left node from incoming data
      temp->left = new Node(data);
      q.push(temp->left);
    }


   cout<<"enter the data for right node: "<<endl;
    
    cin>> data;
    if(data != -1){
        // create a right node from incoming data
      temp->right = new Node(data);
      q.push(temp->right);
    }
  }

}   
  


void inOrderTraversal(Node* root){
  // base case
   if(root == NULL){
    return;
   }

   inOrderTraversal(root->left);
   cout<<" "<<root->data;
   inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
  // base case
   if(root == NULL){
    return;
   }

   cout<<" "<<root->data;
   preOrderTraversal(root->left);
   preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
  // base case
   if(root == NULL){
    return;
   }

   postOrderTraversal(root->left);
   postOrderTraversal(root->right);
   cout<<" "<<root->data;
}

int main()
{

  // 1 2 3 -1 -1 -1 2 4 -1 -1 5 -1 -1
  // 1 2 3 -1 -1 1 -1 -1 4 5 -1 -1 3 -1 -1

  Node *root = NULL;

  // root = treebuilder(root);
  // levelOrderTraversal(root);
    // inOrderTraversal(root);
    // preOrderTraversal(root);
    // postOrderTraversal(root);

    buildFromLevel(root);

  return 0;
}