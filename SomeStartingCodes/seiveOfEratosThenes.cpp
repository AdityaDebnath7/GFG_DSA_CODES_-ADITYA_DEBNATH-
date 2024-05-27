#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

void soer(int n)
{
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }

    for (int i = 2; i * i < n; i++)
    {
        if (isPrime(i))
        {
            for (int j = 2 * i; j < n; j = j + i)
            {
                arr[j] = 1;
            }
        }
    }
    for (int k = 2; k < n; k++)
    {
        if (arr[k] == 0)
        {
            cout << k << ",";
        }
    }
}

void Prosoer(int n)
{
    int f = 0;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime(i))
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                arr[j] = 1;
            }
        }
    }
    for (int k = 2; k < n; k++)
    {
        if (arr[k] == 0)
        {
            f++;
            cout << k << ",";
        }
    }
    cout <<endl<< "total " << f << " prime number"<<endl;
}

/*naive method of running the loop till n and checkinf wheather it is prime or not and then printing will have time
complexrity O(n*root n) but above algorithm is seive of eratosthenes and has time complexeity of O(nloglogn) and auxiliary space O (n)*/
int main()
{
    int t = 0;
    {
        while (t <= 3)
        {
            /* code */

            int a;
            cout << "enter number";
            cin >> a;
            Prosoer(a);
            t++;
        }
    }

    return 0;
}