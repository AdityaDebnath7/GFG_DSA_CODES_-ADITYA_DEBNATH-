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
int isBalanced(Node *root){
    if(root==NULL)
        return 0;
    int lh=isBalanced(root->left);
    if(lh==-1)return -1;
    int rh=isBalanced(root->right);
    if(rh==-1)return -1;
    
    if(abs(lh-rh)>1)
        return -1; 
    else
        return max(lh,rh)+1;
}


int main() {
 

     return 0 ;
}