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

int res = 0;   // to hold max of the updated result

int burntime(Node *root, int leaf, int &dist)  // dist will hold distance of node from leaf if it is decendent

{
    if (root == NULL)
    {
        return 0;
    }

    if (root->key == leaf)
    {
        dist = 0;
        return 1;
    }

    int ldis = -1;
    int rdis = -1;

    int lh = burntime(root->left, leaf, ldis);
    int rh = burntime(root->right, leaf, rdis);

    if (ldis != -1)
    {
        dist = ldis + 1;

        res = max(res, rh + ldis + 1);
    }

    if (rdis != -1)
    {
        dist = rdis + 1;

        res = max(res, lh + rdis + 1);
    }

    return max(rh, lh) + 1;
}
int main()
{




    return 0;
}