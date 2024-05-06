#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void iSort(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{

    int a[] = {1,4,5,3,2};
   iSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}