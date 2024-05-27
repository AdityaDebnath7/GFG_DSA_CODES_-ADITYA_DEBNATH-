#include <iostream>
using namespace std;

int gcd1(int a, int b)
{
    int x, y, res;

    if (a <= b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }

    for (int i = 1; i <= x; i++)
    {
        if ((x % i == 0) && (y % i == 0))
        {
            res = i;
        }
    }
    return res;
}
int gcd2(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {

        return gcd2(b, a % b);
    }
}

int main()
{
    int i = 1, a, b;
    while (i <= 3)
    {
        cout << "enter two numbers" << endl;
        cin >> a;
        cin >> b;
        cout << endl;
        cout << gcd2(a, b);
        i++;
    }

    return 0;
}