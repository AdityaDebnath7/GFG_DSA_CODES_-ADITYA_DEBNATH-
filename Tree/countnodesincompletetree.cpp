#include <iostream>
using namespace std;
#include <algorithm>
#include <cmath>

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

// challenge is to calculate in O(logn*logn) time compleixity;

int lh(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    else
        return 1 + lh(root->left);
}

int rh(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    else
        return 1 + rh(root->right);
}

int count_node(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (lh(root) == rh(root))
    {
        return int(pow(2, lh(root)))-1;
    }

    else
        return 1 + count_node(root->left) + count_node(root->right);
}

int main()
{


    return 0;
}