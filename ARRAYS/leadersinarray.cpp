#include <iostream>
using namespace std;
    

    void Leaders(int arr[],int n){
        cout<< arr[n-1]<<",";
        int currentleader= arr[n-1];
        for (int i = n-2; i>=0; i--)
        {
            if (arr[i]>currentleader)
            {
                cout<<arr[i];
                arr[i]= currentleader;
            }
            
        }
        
    }
int main() {
 

     return 0 ;
}