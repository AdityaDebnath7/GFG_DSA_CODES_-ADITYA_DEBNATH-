#include <iostream>
using namespace std;
#include <queue>
#include <stack>

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
// stack based iteration over tree
//(inorder)
void iterative_inorder(Node *root)
{
    stack<Node *> stk;

    Node *curr = root;

    while ((curr != NULL) || !(stk.empty()))
    {
        while (curr != NULL)
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();

        cout << curr->key << " ";

        curr = curr->right;
    }
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
   iterative_inorder(root);

    return 0;
}