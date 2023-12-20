#include <iostream>
using namespace std;

// int pow(int x, int n)
// {
//     int a;
//    a=x;
//     if (n == 0)
//     {
//         return 1;                                                    // THIS IS NAIVE METHOD
//     }

//     else

//         for (int i = 1; i < n; i++)
//         {
//             a = a * x;
//         }
//         return a;

// }

int propower(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    int temp = propower(x, n / 2);                              // THIS IS PRO METHOD IN RECURSIVE WAY
    temp = temp * temp;
    if (n % 2 == 0)
    {
        return temp;
    }
    else
    {
        return temp * x;
    }
}
int main()
{
    int t = 0;
    {
        while (t <= 3)
        {
            /* code */

            int a, b;
            cout << "enter base";
            cin >> a;
            cout << endl;
            cout << "enter power";
            cin >> b;
            cout << endl;
            cout << propower(a, b);
            t++;
            
        }
    }
    return 0;
}