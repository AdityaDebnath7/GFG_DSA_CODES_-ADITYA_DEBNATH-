#include <iostream>
using namespace std;
// to tel  wheather we have two elememnts in array whose sum is equal to x or not , given array is SORTED

int issum(int arr[], int n, int x)
{
    int i = 0, j = n - 1;

    while (j > i)
    {
        if (arr[i] + arr[j] == x)
        {
            return 1;
        }
        if (arr[i] + arr[j] > x)
        {
            j--;
        }
        else
            i++;
    }
    return 0;

}
int main()
{

int arr[]={2,5,8,12,18};
int brr[]={3,8,13,18};

cout<<issum(arr,5,17)<<endl;
cout<<issum(brr,4,14);
//cout<<"hi";
    return 0;
}