#include <iostream>
using namespace std;

class GFG
{
public:
    static void printFactors(int n)
    {
        int i;
        for (i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << i << " ";
            }
        }
        for (; i > 1;)
        {
            i--;
            if (i != n / i && n % i == 0)
                cout << n / i << " ";
        }
    }
};
int main()
{
    GFG gfg;
    int n;
    cin >> n;

    gfg.printFactors(n);

    return 0;
}