#include <iostream>
using namespace std;
#include <vector>
#include <stack>

vector<long long> nextLargerElement(vector<long long> arr, int n)
{

    stack<long long int> s;
    vector<long long int> res(n);
    res[n - 1] = -1;
    s.push(n - 1);

    int i = n - 2;

    while (i >= 0)
    {

        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            res[i] = -1;

            s.push(i);
        }

        else
        {
            res[i] = arr[s.top()];
            s.push(i);
        }
        i--;
    }

    return res;
    

}

    int main()
    {

        return 0;
    }