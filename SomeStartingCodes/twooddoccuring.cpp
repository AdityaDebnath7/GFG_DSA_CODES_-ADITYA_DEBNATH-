#include <iostream>
using namespace std;

bool kbit_chk(int n, int k)
{ // this is optimised sol using bitwise right shift operators
    int x;
    x = (n >> (k - 1));
    if (x & 1 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int twoodd(int arr[], int n)
{

    

}

int main()
{

    return 0;
}