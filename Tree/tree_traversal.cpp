#include <bits/stdc++.h>
using namespace std;

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

void Print_tree(Node *root)
{
    cout << root->key << "," << endl;

    if (root->left != NULL)
        Print_tree(root->left);
    if (root->right != NULL)
        Print_tree(root->right);
    
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    Print_tree(root);

}