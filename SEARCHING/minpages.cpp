#include <iostream>
using namespace std;
#include <climits>

int sum(int arr[], int left, int right)
{
    int add = 0;

    for (int i = left; i <= right; i++)
    {
        add += arr[i];
    }
    return add;
}

int max(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
// int findPages1(int arr[], int n, int k) //                               NAIVE log krte hai aese

// {
//     if (k == 1)
//     {
//         return sum(arr, 0, n - 1);
//     }
//     if (n == 1)
//     {
//         return arr[0];
//     }

//     int res = INT_MAX;

//     for (int i = 1; i < n; i++)
//     {

//         res = min(res, max((arr, i, k - 1), sum(arr, i, n - 1)));
//     }

//     return res;
// }

int minpagebinary(int arr[], int n, int k) // using binary search

{

    int low = max(arr, n);

    int high = sum(arr, 0, n - 1);
    int res = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int studentsrequired;
        int i = 0;
        int sumofpages=0;

        while (i < n)
        {
            sumofpages = arr[i];

            while ((sumofpages <= mid) && i < n-1)
            {
                sumofpages += arr[i+1];
                i++;
            }
            studentsrequired++;
        }

        if (studentsrequired <= k && studentsrequired>0)
        {
            res = mid;

            high = mid - 1;
        }
        else
            low = mid + 1;


      
    }

    if (res != 0)
    {
        return res;
    }
    else
        return -1;
}

int main()
{

    int arr[] = {12, 34, 67, 90};
    cout << minpagebinary(arr, 4, 2) << endl;

    return 0;
}