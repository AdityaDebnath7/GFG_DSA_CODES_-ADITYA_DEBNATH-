#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

string infixToPostfix(const string &s)
{
    stack<char> stk;
    string res;

    unordered_map<char, int> m;
    m['('] = 0;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m['^'] = 3;
    m[')'] = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (m.find(s[i]) == m.end())
        {
            res.push_back(s[i]);
        }
        else
        {
            if (s[i] == '(')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.pop(); // Pop the '('
            }
            else
            {
                while (!stk.empty() && m[stk.top()] >= m[s[i]])
                {
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
    }

    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }

    return res;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
