#include <iostream>
using namespace std;
#include <map>
#include <vector>

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

void vertical_sum_util(Node *root, map<int, int> &m, int dis, int &mini, int &maxi)
{

    if (root == NULL)
        return;

    m[root->key] = dis;

    vertical_sum_util(root->left, m, dis - 1, mini, maxi);
    mini = min(mini, dis);

    vertical_sum_util(root->right, m, dis + 1, mini, maxi);
    maxi = max(maxi, dis);
}

vector<int> vertical_sum_vector_util(map<int, int> &m, int &mini, int &maxi)
{
    vector<int> res(maxi - mini + 1, 0);

    map<int, int>::iterator it = m.begin();

    for (it; it != m.end(); it++)
    {
        res[it->second - mini] = res[it->second - mini] + it->first;
    }

    return res;
}

vector<int> Vertical_Sum(Node *root)
{
    map<int, int> map;

    int mini = 0;
    int dis = 0;
    int maxi = 0;

    vertical_sum_util(root, map, dis, mini, maxi);

    return vertical_sum_vector_util(map, mini, maxi);
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(25);
    root->left->left = new Node(35);
    root->left->right = new Node(20);
    root->left->right->right = new Node(75);
    root->left->right->right->right= new Node(80);
    root->left->left->left = new Node(40);
    

    vector<int> res;
    res= Vertical_Sum(root);

    for (auto x :res)
    {
        cout<<x<<" ";
    }
    

    return 0;
}