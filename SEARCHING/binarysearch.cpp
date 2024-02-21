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

int binserrec(int arr[], int n, int k, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int x = (low + high) / 2;
    if (k == arr[x])
    {
        return x;
    }
    else if (k > arr[x])
    {
        return binserrec(arr, n, k, x + 1, high);
    }
    else if (k < arr[x])
    {
        return binserrec(arr, n, k, low, x - 1);
    }
}

// code for first index of required number if its there using binary search

int firstocc(int arr[], int n, int k, int low, int high)
{
    int x;
    while (low < high)

    {
        x = (low + high) / 2;

        if (k == arr[x])
        {

            while (arr[x] == arr[x - 1] && x > 0)
            {
                x = x - 1;
            }
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

int lastocc(int arr[], int n, int k, int low, int high)
{
    int x;
    while (low < high)

    {
        x = (low + high) / 2;

        if (k == arr[x])
        {

            while (arr[x] == arr[x + 1] && x < n - 1)
            {
                x = x + 1;
            }
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

int countocc(int arr[], int n, int k, int low, int high)
{
    return ( lastocc(arr, n, k, low, high) - firstocc(arr, n, k, low, high) +1 );
}

int main()
{

    int arr[] = {10, 20, 24, 40, 40, 60};
    int brr[] = {10, 15, 25};
    int crr[] = {5, 5, 15, 30};
    cout << firstocc(arr, 6, 40, 0, 5) << endl;
    cout << firstocc(brr, 3, 15, 0, 2) << endl;
    cout << firstocc(crr, 4, 5, 0, 3) << endl<<endl;

    cout << lastocc(arr, 6, 40, 0, 5) << endl;
    cout << lastocc(brr, 3, 15, 0, 2) << endl;
    cout << lastocc(crr, 4, 5, 0, 3) << endl<<endl;

    cout << countocc(arr, 6, 40, 0, 5) << endl;
    cout << countocc(brr, 3, 15, 0, 2) << endl;
    cout << countocc(crr, 4, 5, 0, 3) << endl<<endl;



    return 0;
}