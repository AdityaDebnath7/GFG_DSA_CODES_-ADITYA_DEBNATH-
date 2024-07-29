#include <iostream>
using namespace std;
int res = 0;

int knapsack(int v[], int w[], int n, int W)
{
    // base cases

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (w[n - 1] > W)
    {
        return knapsack(v, w, n - 1, W);
    }

    else
    {

        return max(knapsack(v, w, n - 1, W), v[n - 1] + knapsack(v, w, n - 1, W - w[n - 1]));
    }
}

// dynamic approach

int knapsackdp(int v[], int w[], int n, int W)
{
    // as two variable changing dimension of dp array should be 2

    int dp[n + 1][W + 1];

    // 1st row and first column should have zeroes

      for(int i=0; i<=W; i++)
   {
       dp[0][i] = 0;
   }
   
   for(int i=0; i<=n; i++)
   {
       dp[i][0] = 0;
   }
    

    // now look in what fashion the array should be filled!

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            //  write the cases for deciding which prior cells to use to fill array

            if (w[i-1]>j)
            {
                dp[i][j] = dp[i - 1][j]; // case of not including and just ignoring the if given weight greater than W
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], v[i-1] + dp[i - 1][j - w[i-1]]);
            }
        }
    }

    return dp[n][W];
}


 int knapSack(int W, int wt[], int val[], int n) 
{ 
  
    
    int i, j; 
    int dp[n + 1][W + 1]; 
  
   for(int i=0; i<=W; i++)
   {
       dp[0][i] = 0;
   }
   
   for(int i=0; i<=n; i++)
   {
       dp[i][0] = 0;
   }
    
    for (i = 1; i <= n; i++) {  
        for (j = 1; j <= W; j++) { 
           if (wt[i - 1] > j) 
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);  
        } 
    } 
  
    return dp[n][W]; 
} 
   
int main()
{
     int v[]= {10,40,30,50};
     int w[]= {5,4,6,3};
     int W= 10;
     int n= 4;

     cout<<knapsackdp(v,w,n,W);


    return 0;
}