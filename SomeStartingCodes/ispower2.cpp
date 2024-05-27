#include <iostream>
using namespace std;

bool ispower2(int n)
{
    if (n == 0)
    {                                                     // this efficient solution of this problem using brian kernigham algo...
        return false;
    }
                                                           // T: theta(1)
    if ((n & (n - 1)) == 0)
    {
        return true;
    }
    else return false;
}
int main()
{
int a= 4;int b=7;int c=32;
cout<<ispower2(a)<<endl;
cout<<ispower2(b)<<endl;
cout<<ispower2(c)<<endl;
    return 0;
}