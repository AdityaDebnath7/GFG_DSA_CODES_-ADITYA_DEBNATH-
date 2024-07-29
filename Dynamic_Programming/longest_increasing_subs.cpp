#include <iostream>
using namespace std;

int lis(int arr[], int n)

{
    // dp with ending indx
    int dp[n];
    dp[0] = 1;
    int prevmax=arr[0];


    for (int i = 1; i < n; i++)
    {
        if (arr[i] > prevmax)
        {
            dp[i] = dp[i - 1] + 1;
            prevmax= arr[i];

        }

        else
        {
            dp[i] = dp[i - 1];
        }
    }


    return dp[n-1];

}

int main()
{


int arr[]={3,4,2,8,10};

cout<<lis(arr,5);



    return 0;
}