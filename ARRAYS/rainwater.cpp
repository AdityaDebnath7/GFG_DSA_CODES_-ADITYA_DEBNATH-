#include <iostream>
using namespace std;
    

    int maxwrainwater(int arr[],int n){
        int lmax[n];int rmax[n];
         lmax[0]= arr[0];
         rmax[n-1]=arr[n-1];
         int res=0;
        for (int i = 1; i < n; i++)
        {
           lmax[i]= max(arr[i],lmax[i-1]);
        }
        for (int i = n-2; i >=0; i--)
        {
            rmax[i]= max(arr[i],rmax[i+1]);
        }
        
        for (int i = 1; i < n-1; i++)
        {
            res+=min(rmax[i],lmax[i])-arr[i];
        }
        
        
        
    }
int main() {
 

     return 0 ;
}