#include <iostream>
using namespace std;
const int INF = 1e9;
int mincoins(int coin[], int n, int sum)
{
    if (sum == 0)
    {
        return 0;
    }
    int res = INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        if (coin[i] - sum >= 0)
        {
            int subres = mincoins(coin, n, sum - coin[i]);

            if (subres != INT16_MAX)
            {
                res = min(res, subres + 1);
            }
        }
    }

    return res;
} // this was recursive solution
// lets do it in dynamic approach
int mincoindp(int arr[], int m, int value)
{

    int dp[value + 1];

    dp[0] = 0;

    for (int i = 1; i <= value; i++)
        dp[i] = INF;

    for (int i = 1; i <= value; i++)
    {

        for (int j = 0; j < m; j++)
            if (arr[j] <= i)
            {
                int sub_res = dp[i - arr[j]];
                if (sub_res != INF && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
    }
    return dp[value];
}

int main()
{
    int arr[] = {3, 4, 1};
    cout << mincoindp(arr, 3, 5);
    return 0;
}