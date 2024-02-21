#include <iostream>
using namespace std;

bool issum(int arr[], int first, int last, int x)
{
    int i = first, j = last;

    while (j > i)
    {
        if (arr[i] + arr[j] == x)
        {
            return 1;
        }
        if (arr[i] + arr[j] > x)
        {
            j--;
        }
        else
            i++;
    }
    return 0;
}
int sumarray(int arr[], int n)
{
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        return sum;
    }
}

bool istriplet(int arr[], int n, int x)
{
    int total = x;

    for (int i = 0; i < n; i++)
    {
        int a = arr[i];

        if (issum(arr, i + 1, n - 1, total - arr[i]))
        {
            return true;
            break;
        }
    }

    return false;
}
int main()
{

    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int brr[] = {4, 8, 20};
    cout << int(istriplet(arr, 7, 32));
    cout << int(istriplet(brr, 3, 14));
    return 0;
}