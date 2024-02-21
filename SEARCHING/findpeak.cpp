#include <iostream>
using namespace std;

int getpeak(int arr[], int n)

{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {

        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (arr[mid] >= arr[mid + 1] || mid == n - 1))
        {
            return arr[mid];
        }
        else if ( mid > 0 && (arr[mid - 1] >= arr[mid]))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[]={5,10,2,13,7};
    int brr[]={10,30,15,5,23,90,65};
    cout<<getpeak(arr,5);
    cout<<getpeak(brr,7);


    return 0;
}