#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <unordered_map>

long int factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;

    long int sum = 1;

    for (int i = 2; i <= n; i++)
    {
        sum *= i;
    }

    return sum;
}

int smaller_string(string s, int low, int high)
{
    if (low == high)
    {
        return 0;
    }

    int sm = 0;
    for (int i = low+1; i <=high; i++)
    {
        if (int(s[i]) < int(s[low]))
        {
            sm++;
        }

        
    }
    return sm * factorial(high-low);
}

int findRank(string S)
{
    int sum = 0;

    for (int i = 0; i < S.length(); i++)
    {
        sum = sum + smaller_string(S,i,S.length()-1);
    }

    return sum + 1;
}

int main()
{

    string A = "aac";
    cout << findRank(A);

    return 0;
}