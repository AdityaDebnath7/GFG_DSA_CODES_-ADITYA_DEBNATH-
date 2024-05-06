#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int temp[high + 1]; // array sorted from low to mid and mid+1 to high

    int mid1 = mid + 1;

    int i = 0;
    int a = low;
    int b = high;

    while (low <= mid && mid1 <= high)

    {
        if (arr[low] < arr[mid1])
        {
            temp[i] = arr[low];
            low++;
            i++;
        }
        else
        {
            temp[i] = arr[mid1];
            mid1++;
            i++;
        }
    }

    while (low <= mid)
    {
        temp[i] = arr[low];
        i++;
        low++;
    }

    while (mid1 <= high)
    {
        temp[i] = arr[mid1];
        i++;
        mid1++;
    }

    for (int j = 0; j < high; j++)
    {
        arr[a + j] = temp[j];
    }
}

void mergeSort(int arr[],int l,int r){
    if(r>l){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{

    int arr[] = {1,5,8,10,2,3,4,0};
    mergeSort(arr, 0,7);

    for (int j = 0; j < 8; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}