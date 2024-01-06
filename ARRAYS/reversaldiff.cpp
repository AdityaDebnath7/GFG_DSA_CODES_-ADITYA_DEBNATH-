#include <iostream>
using namespace std;
    
void swap(int *a, int* b){
    int temp;
    temp = *a;
    *a=*b;
    *b= temp;
}
    void reversal (int arr[], int n){
        if(n%2!=0){
        for (int i = 0; i <= n/2; i++)
        {
            swap(arr[i],arr[n-1-i]);
        }
        }
        if(n%2==0){
        for (int i = 0; i < n/2; i++)
        {
            swap(arr[i],arr[n-1-i]);
        }
        }

    }
int main() {
 
 int arr[]={1,2,3,4,5};
 reversal(arr, 5);
 for (int  i = 0; i < 5; i++)
 {
    cout<<arr[i];
 }
 

     return 0 ;
}