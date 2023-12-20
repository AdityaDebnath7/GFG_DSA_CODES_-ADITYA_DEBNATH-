#include <iostream>
using namespace std;

int countdigits(int n)
{
    int k = 0;
    while (n>0)
    {
        k++;
        n = n / 10;
    }

    return k;
}

int main()
{kil:
    long int a;
    cout << "enter number";
    cin >> a;
    cout << "the number of digits in you numbe is " << countdigits(a) <<endl;
    goto kil;

    return 0;
}