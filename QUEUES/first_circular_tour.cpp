#include <iostream>
using namespace std;
#include <queue>
#include <vector>

int petrol_pump(int a[], int b[], int n)

{

    int start = 0;
    int prev_petrol = 0;
    int curr_petrol = 0;

    for (int i = 0; i < n; i++)
    {
        curr_petrol = a[i] - b[i];

        if (curr_petrol < 0)
        {
            start = i + 1;
            prev_petrol += curr_petrol;
            curr_petrol = 0;
        }
    }

    return (curr_petrol + prev_petrol >= 0) ? start + 1 : -1;
}

int main()
{

    return 0;
}