#include <iostream>
using namespace std;

int largest(int arr[], int n)
{
    int res = 0;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
            ;
        }
    }
    return res;
}

int secondlargest(int arr[], int n)
{
    int a = largest(arr, n);

    int res = -1;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[a])
        {
            if (res == -1)
            {
                res = i;
            }
            else if (arr[i] > arr[res])
            {
                res = i;
            }
        }
    }
    return res;
}

int main()
{

    int arr[] = {2, 3, 4, 5, 8, 1};
    cout << secondlargest(arr, 6);

    return 0;
}