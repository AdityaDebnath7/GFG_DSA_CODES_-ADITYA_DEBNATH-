#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    int x; // x is index of mid
    while (low <= high)

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
   
   return -1;
}
int main()
{

    int arr[] = {10, 20, 30, 40, 50, 60};
    int brr[] = {10, 15, 25};
    int crr[] = {5, 10, 15, 30};
    cout << binarysearch(arr, 6, 20) << endl;
    cout << binarysearch(brr, 3, 15) << endl;
    cout << binarysearch(crr, 4, 25) << endl;
    cout << "hrllo";
    return 0;
}