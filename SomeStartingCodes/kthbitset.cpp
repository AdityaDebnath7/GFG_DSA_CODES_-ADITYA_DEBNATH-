#include <iostream>
using namespace std;

void kbit_chk(int n, int k)
{ // this is optimised sol using bitwise right shift operators
     int x;
     x = (n >> (k - 1));
     if (x & 1 != 0)
     {
          cout << "yes";
     }
     else
     {
          cout << "no";
     }
}
// it can be done using left shift byt moving 1 by required times and then taking &(AND) with that.
// or it can be done by checking with &(AND) with 2 to the power k-1 method.
int main()
{
     kbit_chk(5, 3);

     return 0;
}