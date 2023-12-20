#include <iostream>
using namespace std;


void powerset(int arr[],int n)
{
    int psize = (1 << n);
    for (int i = 0; i < psize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                cout << arr[j]<<"," ;
            }
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout << "enter the number of elements in your list";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        
    }
    powerset(array, n);
 

    
     return 0 ;
}