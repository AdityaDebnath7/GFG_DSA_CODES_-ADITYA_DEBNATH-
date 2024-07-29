#include <iostream>
using namespace std;

const int INF = 1e9;

int minjumps(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int res = INF;
    for (int i = 0; i < n - 1; i++)
    {
        if (i + arr[i] >= n - 1)
        {
            int subres = minjumps(arr, i + 1);
            if (subres != INF)
            {
                res = min(res, subres + 1);
            }
        }
    }

    return res;
}

// dp based approach

int minjumpsdp(int arr[], int n)
{

    int dp[n];
    int i, j;

    dp[0] = 0;

    for (i = 1; i < n; i++)
    {
        dp[i] = INF;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && dp[j] != INF)
            {
                dp[i] = min(dp[i], dp[j] + 1);
              
            }
        }
    }
    return dp[n - 1];
}

int main()
{

    int arr[] = {4, 1, 5, 3, 1, 3, 2, 1, 8};
    cout << minjumpsdp(arr, 9);

    return 0;
}