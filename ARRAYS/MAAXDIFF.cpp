#include <iostream>
using namespace std;
    

// this is efficient approach working in theta n time compleixity !

int maxdiff(int arr[], int n){
    int res = arr[1]-arr[0];
int minvalue=arr[0];

 
for (int i = 0; i < n; i++)
{
    res= max(res, arr[i]- minvalue);
    minvalue= min(arr[i],minvalue);

}
return res;




}
int main() {
    int array[]={2,3,4,5,6};
  cout<<maxdiff(array,5);
 

     return 0 ;
}