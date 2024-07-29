#include <iostream>
using namespace std;
    
// code for binary search in sorted array to reach upto ceiling integer's index
int ceilIdx(int tail[], int l, int r, int key)
{
    while (r > l)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
            r = m;
        else
            l = m + 1;
    }

    return r;
}

int LIS(int arr[], int n)
{

    int tail[n];
    int len = 1;

    tail[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        if (arr[i] > tail[len - 1])
        {
            tail[len] = arr[i];
            len++;
        }
        else
        {
            int c = ceilIdx(tail, 0, len - 1, arr[i]);

            tail[c] = arr[i];
        }
    }

    return len;
}    



int main() {
  
  pair<int,int>a={1,2};
  cout<<a.second;


     return 0 ;
}