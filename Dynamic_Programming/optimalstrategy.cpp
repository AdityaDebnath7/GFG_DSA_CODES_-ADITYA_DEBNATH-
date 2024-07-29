#include <iostream>
using namespace std;
    

// recursive 1

int solr1(int arr[], int i, int j, int sum){

    if (i+1==j)
    {
        return max(arr[i],arr[j]);

    }

    else{

        return max(sum-solr1(arr,i+1,j,sum-arr[i]),sum-solr1(arr,i,j-1,sum-arr[j]));
    }
    
}

// recursive 2

int solr2(int arr[], int i, int j)
{


    if (i+1==j)
    {
        return max(arr[i],arr[j]);
    }

    else{

        return max( arr[i]+min(solr2(arr,i+2,j),solr2(arr,i+1,j-1)), arr[j]+ min(solr2(arr,i,j-2),solr2(arr,i+1,j-1)));

    }
    

}
// this rec 2 method can be efficiently converted to dp based solution


// DP BASED

int optimalStrategy_dp(int arr[],int n)
{

   int dp[n][n];

   // base case when i+1=j
    
    for (int k = 0; k<n-1; k++)
    {
       dp[k][k+1]= max(arr[k],arr[k+1]);
    }
    
    if (n==2)
    {
       return dp[0][1];
    }
   

    for (int  k = 3; k < n;k=k+2)
    {
        int j=k;
        int i=0;
       while (j<n&&(i+2)<n)
       {
         dp[i][j]= max(   arr[i]+min(dp[i+2][j],dp[i+1][j-1]),  arr[j]+min(dp[i+1][j-1],dp[i][j-2])  );


         i++;j++;
       }
       
    }
    
    return dp[0][n-1];  // sol when i=0 and j=n;


}


//
int main() {
 

 int arr[]={20,5,4,6};

 cout<<optimalStrategy_dp(arr,4);


     return 0 ;
}