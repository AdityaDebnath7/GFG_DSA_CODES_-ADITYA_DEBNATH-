#include <iostream>
using namespace std;
# include <limits>


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

int max_tree(Node* root)
{
   if(root== NULL)return ;


   else return max(root->key,max_tree(root->left),max_tree(root->right));
   



}



int main() {
 

     return 0 ;
}