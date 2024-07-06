#include <iostream>
using namespace std;
#include <queue>

struct Node
{
    int key;
    struct Node *left;  // left pointer
    struct Node *right; // right pointer
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

queue<Node *> q;

// converting binary tree to doubly linked list in the inorder traversal
void make_queue(Node *root)
{
    if (root == NULL)
        return;
                                      //making a queue of Node* storing node in inorder traversal
                                      // then linking the nodes in doubly linked list fashion
    else
    {

        if (root->left)
            make_queue(root->left);

        q.push(root);

        if (root->right)
            make_queue(root->right);
    }
}

Node *bToDLL(Node *root)
{
while (!q.empty()) {
            q.pop();
        }
        
        make_queue(root);
        
        if (q.empty()) return NULL; // If the tree is empty, return NULL
        
        Node* head = q.front();
        q.pop();
        
        Node* prev = head;
        prev->left = NULL; // Head's left should be NULL
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            prev->right = curr;
            curr->left = prev;
            prev = curr;
        }
        
        // Last node's right should be NULL
        if (prev != NULL) {
            prev->right = NULL;
        }
        
       
       return head;
      // head->left=NULL;
       
       //q.front()->right=NULL;
       
       return head;
       
}
int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    make_queue(root);

    while (!q.empty())

    {
        cout << q.front()->key << ",";
        q.pop();
    }

    return 0;
}