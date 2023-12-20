#include <iostream>
using namespace std;

int findodd(int arr[], int n)
{
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = (res ^ arr[i]);
    }
    return res;
}
int main()
{
    int n;
    cout << "enter the number of elements in your list";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        
    }
    cout << findodd(array, n);

    return 0;
}