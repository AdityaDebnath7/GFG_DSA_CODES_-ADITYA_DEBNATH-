#include <iostream>
using namespace std;

// MAIR= maximum appearing elements in ranges

int MAIR(int arr[], int brr[], int n)
{
    for (int i = 0; i < n; i++)  // constraint 1
    {
        if (arr[i] > brr[i])
        {
            cout << "Wrong entries. code terminated";
            return 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)   // constraint 2
    {
        if (brr[i] >= 100)
        {
            return 0;
        }
    }






}
int main()
{

    return 0;
}