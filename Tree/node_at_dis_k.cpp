#include <iostream>
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

int maxheight(Node *root)
{
    if (root == NULL)
        return 0;

    else
        max(maxheight(root->left), maxheight(root->right)) + 1;
}

void nodeatkdis(Node *root, int k)
{
    if (k == 0)
    {
        cout << root->key << ", ";
        return;
    }

    if (root->left != NULL)
    {
        nodeatkdis(root->left, k - 1);
    }

    if (root->right != NULL)
    {
        nodeatkdis(root->right, k - 1);
    }
}

void levelorder(Node *root)
{

    int max_h = maxheight(root);

    for (int i = 0; i < max_h; i++)
    {
        nodeatkdis(root, i);
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
    
    // nodeatkdis(root,2);


    levelorder(root);
    // this is computationally very costly


    return 0;
}