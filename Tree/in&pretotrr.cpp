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



int preIndex=0;
Node *cTree(int in[],int pre[],int is,int ie){
    if(is>ie)return NULL;
    Node *root=new Node(pre[preIndex++]);
    
    int inIndex;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex=i;
            break;
        }
    }
    root->left=cTree(in, pre, is, inIndex-1);
    root->right=cTree(in, pre, inIndex+1, ie);
    return root;
}

int main() {
 

     return 0 ;
}