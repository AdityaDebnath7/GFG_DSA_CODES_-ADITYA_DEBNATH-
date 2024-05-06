#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    int x; // x is index of mid
    while (low < high)

    {
        x = (low + high) / 2;

        if (k == arr[x])
        {

            return x;
        }

        else if (k > arr[x])
        {
            low = x + 1;
        }
        else if (k < arr[x])
        {
            high = x - 1;
        }
    }
}

// SRABS = sorted rotated array binary search
int SRABS(int arr[], int i, int f, int k)
{
    
}
int main()
{


    int arr[]={10,20,30,40,50,8,9};
    int brr[]={100,200,300,10,20};
    cout<<SRABS(arr,0,6,8)<<endl;
     cout<<SRABS(brr,0,4,40);


    return 0;
}