#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
    

void count(int arr[],int n )
{
   unordered_map <int,int> m;
   for (int i = 0; i < n; i++)
   {
    m[arr[i]]++;

   }
  
   for (auto x:m)
   {
     cout<<x.first<<"- "<<x.second<<",";

   }
   
  


} 
int main() {
 
int arr[]={1,1,1,2,3,3};
count(arr,6);



     return 0 ;
}