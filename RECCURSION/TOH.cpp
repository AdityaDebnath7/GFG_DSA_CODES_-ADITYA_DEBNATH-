#include <iostream>
using namespace std;
void TOH(int n, char a, char b, char c)
{

    if (n == 0)
    {
        cout << "invalid input";
    }

    if (n == 1)
    {
        cout << "move disc 1 from " << a << " to " << c << endl;
    }

    else
    {
        TOH(n - 1, a, c, b);
        cout << "move disc " << n << " from " << a << " to " << c << endl;
        TOH(n - 1, b, a, c);
    }
}

void protoh(int n, char a, char b, char c)
{
    cout   << "Total number of moves required is " << ((1 << n) - 1)<<endl;
    TOH(n, 'a', 'b', 'c');
}


int main()
{
    protoh(7, 'a', 'b', 'c');
    return 0;
}