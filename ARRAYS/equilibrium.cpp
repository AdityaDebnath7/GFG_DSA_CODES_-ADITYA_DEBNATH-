#include <iostream>
using namespace std;

bool equilibrium(int arr[], int n)
{                                                    // this is efficient and works on theta n time

    int sumall = 0;
    int sumleft = arr[0];
    for (int j = 0; j < n; j++)
    {
        sumall += arr[j];
    }

    for (int i = 1; i < n; i++)

    {
        if (sumleft == (sumall - (sumleft + arr[i])))
        {
            return true;
        }

        sumleft += arr[i];
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    int brr[] = {4, 5, 2};
    cout << equilibrium(arr, 6) << endl;
    cout << equilibrium(brr, 3) << endl;
    return 0;
}