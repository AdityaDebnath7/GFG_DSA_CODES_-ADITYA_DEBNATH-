#include <iostream>
using namespace std;
#include <vector>
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

void printLevel(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << '\n';
            q.push(NULL);

            continue;
        }

        cout << curr->key << " ,";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

// serialise

const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

// deserialising the vector and making the tree;
// Node* prev = NULL;

Node *deSerialize(vector<int> &arr, int &index)
{
    if (index == arr.size())
        return NULL;
    int val = arr[index];
    index++;
    if (val == EMPTY)
        return NULL;
    Node *root = new Node(val);
    root->left = deSerialize(arr, index);
    root->right = deSerialize(arr, index);
    return root;
}


int main()
{

    vector<int> arr;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    serialize(root, arr);

    for (int
             x : arr)
    {
        cout << x << ",";
    }
    int x = 0;

    // deSerialize(arr,x);

    printLevel(deSerialize(arr, x));

    return 0;
}