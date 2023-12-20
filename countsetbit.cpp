#include <iostream>
using namespace std;
bool kbitck(int n, int k)

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

int setbit(int n)
{
    // largest value that can be stored in int 2147483647 that is 2 to the power 31 minus 1 as 32 bit representation.
    int set = 0;
    for (int i = 1; i <= 32; i++)
    {
        if (kbitck(n, i))                                          // this is naive method 
        {
            set= set +1;
        }
    }
    return set;
}


int main()
{ int t=1;

while(t<4){
       int a;
    cout << "enter number";
    cin >> a;
    cout << "Total number of set in in "<<a<<"is "<<setbit(a)<<endl;
    t++;
}
    return 0;
}