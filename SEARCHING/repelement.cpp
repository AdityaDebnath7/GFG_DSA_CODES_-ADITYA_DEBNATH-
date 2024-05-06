#include <iostream>
using namespace std;
#include <algorithm>


int repetingelement1(int arr[], int n)          // for array starting from 1 to n-1 numbers
                                               // need to modify this code from working number starting from 0 as well;
{
     int slow = arr[0];
     int fast = arr[0];
     do
     {
          slow = arr[slow];
          fast = arr[arr[fast]];

     } while (slow != fast);

     slow = arr[0];

     do
     {
          slow = arr[slow];
          fast = arr[fast];
     } while (slow != fast);
     return slow ;
}





int repetingelement2(int arr[], int n)         

{
     sort(arr,arr+n);
     int slow = arr[0];
     int fast = arr[0];
     do
     {
          slow = arr[slow];
          fast = arr[arr[fast]];

     } while (slow != fast);

     slow = arr[0];

     do
     {
          slow = arr[slow];
          fast = arr[fast];
     } while (slow != fast);
     return slow;
}



int main()
{
     int arr[] = {1, 2, 7, 3, 4, 5, 6, 7};
     cout << repetingelement1(arr, 8);

     return 0;
}