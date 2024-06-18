#include <iostream>
using namespace std;

typedef struct Node
{

    int data;
    Node *next;
    Node(int x)
    {

        data = x;
        next = NULL;
    }
} Node;

int main()
{

    Node* head = new Node(10);
    Node* first = new Node(11);
    Node* second = new Node(12);
   head->next=first;
   first->next=second;


   for (auto i = head; i!=NULL; i=i->next)
   {
    cout<<i->data<<endl;
   }
   


    return 0;
}