#include <iostream>
using namespace std;

// Time compleixity: O(n)
// theta 1 aux space //  given array is sorted
void freq(int arr[], int n)
{

    int i = 0;
    while (i < n)

    {

        int count = 1;
        cout << arr[i] << " --> ";
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
            if (arr[j]!= arr[i])
            {
                break;
            }
            
        }
        cout << count << endl;
        i = i + count;
    }
}
int main()
{
    int n;
  
    cout << "enter the size of array";
   cin>>n;
     int array[n];
    for (int j = 0; j < n; j++)
    {
        cin>>array[j];
    }


    freq(array, n);

    return 0;
}