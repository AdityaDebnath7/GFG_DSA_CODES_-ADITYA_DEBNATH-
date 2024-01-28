#include <iostream>
using namespace std;

bool parity(int n)
{

    if (n % 2 == 0)
    {
        return true;
    }
    else
        return false;
}

int longestoddeven(int arr[], int n)
{

    int res = 1;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (parity(arr[i]) != parity(arr[i - 1]))
        {
            count++;
        }
        if (parity(arr[i] == parity(arr[i - 1])))
        {
            res = max(res, count);
        }
    }
    return res;
}

int main()
{

    int arr[] = {10, 12, 14, 7, 8};
    int brr[] = {7, 10, 13, 14};
    int crr[] = {10, 12, 8, 4};
    cout << longestoddeven(arr, 5) << endl;
    cout << longestoddeven(brr, 4) << endl;
    cout << longestoddeven(crr, 4) << endl;
    return 0;
}