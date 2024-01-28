#include <iostream>
using namespace std;

int max(int arr[], int n)
{
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    return maximum;
}
int max1array(int arr[], int n) // THIS IS NAIVE SOLUTION WORKING ON O(N^2) TIME COMPLX...
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int current = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)
            {
                current++;
            }
            else
                break;
        }
        res = max(res, current);
    }
    return res;
}

int promax1(int arr[], int n)
{
    int res = 0;
    int count = 0;
                                     // theta n time complexeity
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            res = max(count, res);
        }
        if (arr[i] == 0)
        {
            count = 0;
        }
    }
    return res;
}

int main()
{
    int array[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0};
    cout << promax1(array, 13);
    return 0;
}