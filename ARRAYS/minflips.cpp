#include <iostream>
using namespace std;

void minflips(int arr[], int n)                     // this is naive approach to this problem
{

    int grpone = 0, grpzero = 0, flip; // flip is 1 or 0 depending upon whose groip is less in number

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] == 0)

                grpzero++;
            else
                grpzero++;
        }

        else
        {
            if ((arr[i] == 1) && arr[i] != arr[i - 1])
            {
                grpone++;
            }
            if ((arr[i] == 0) && arr[i] != arr[i - 1])
            {
                grpzero++;
            }
        }
    }

    if (grpone >= grpzero)
    {
        flip = 1;
    }
    else
        flip = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] == flip)
            {
                cout << "from 1 to ";
            }
        }

        else
        {
            if (arr[i] == flip && (arr[i - 1] != flip))
            {
                cout << "from " << i << " to ";
            }
            if (arr[i] != flip && (arr[i - 1] == flip))
            {
                cout << (i - 1)<<endl;
            }
        }
    }
}


void minflipspro(int arr[],int n){

int flip=(1&arr[0]);
// IDEA IS TO FLIP SECOND OCCURING GROUP but using same algooo;


for (int i = 1; i < n; i++)
    {
      
        
        
            if (arr[i] == flip && (arr[i - 1] != flip))
            {
                cout << "from " << i << " to ";
            }
            if (arr[i] != flip && (arr[i - 1] == flip))
            {
                cout << (i - 1)<<endl ;
            }
        
    }
    
}
int main()
{
    int array[] = {1,1,0,0,1,1,0,1};
    minflipspro(array, 8);
    return 0;
}