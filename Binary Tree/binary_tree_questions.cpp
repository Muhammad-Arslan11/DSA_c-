

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

Node *treebuilder(Node* &root)
{
  int data;
  cout << "enter the data" << endl;
  cin >> data;
  if (data == -1)
    {
        root = NULL;
        return NULL;
    }
  root = new Node(data);


  cout << "enter the data for left node: " << data << endl;
  root->left = treebuilder(root->left);
  cout << "enter the data for right node: " << data << endl;
  root->right = treebuilder(root->right);

  return root;
}


void inOrderTraversal(Node* root, int &count){
  // base case
   if(root == NULL){
    return;
   }

   inOrderTraversal(root->left,count);
  
   if(root->left == NULL && root->right == NULL){
    count++;
   }

   inOrderTraversal(root->right,count);
}

int countLeafNodes(Node* root){
    int count =0;
    inOrderTraversal( root, count);

    return count;
}

int main(){
    Node* root = NULL;

    treebuilder(root);
    cout<<countLeafNodes(root);


    return 0;
}