#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

    Node *insert_into_BST(Node *root, int data)
    {
        // base case
        if (root == NULL)
        {
            Node *newNode = new Node(data);
            return newNode;
        }

        // if data is greater than root node: put in right
        if (data > root->data)
        {
            root->right = insert_into_BST(root->right, data);
        }
        // else: put in left
        else
        {
            root->left = insert_into_BST(root->left, data);
        }

        return root;
    }

    void take_input(Node* &root)
    {
        cout << "enter the data: ";
        int data;
        cin >> data;

        while (data != -1)
        {
             root = insert_into_BST(root, data);
            cin >> data;
            
        }
    }

    void levelOrderTraversal(Node* &root)
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


int main()
{
    Node *root = NULL;
    take_input(root);
    levelOrderTraversal(root);
    return 0;
}