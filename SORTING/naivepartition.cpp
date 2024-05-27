#include <iostream>
using namespace std;
#include <algorithm>
void partition(int arr[], int n, int p)
{
    int k = p;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= arr[k] && (i < k))
        {
            
            swap(arr[i],arr[k]);
            k = i;
        }

        if (arr[i] < arr[k] && (i > k))
        {
            
              swap(arr[i],arr[k]);
            k = i;
        }
    }
}

int main()
{
int arr[]={3,8,6,12,10,7};
partition(arr,6,5);

for (int i = 0; i < 6; i++)
{
    cout<<arr[i]<<" ";

}


    return 0;
}