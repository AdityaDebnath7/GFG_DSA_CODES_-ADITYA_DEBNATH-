#include <iostream>
#include <stack>
#include <unordered_set>
#include <string>

using namespace std;

int evaluatePostfix(const string &S)
{
    stack<int> stk;

    unordered_set<char> set;
    for (char ch = '0'; ch <= '9'; ++ch)
    {
        set.insert(ch);
    }

    for (char ch : S)
    {
        if (set.find(ch) != set.end())
        {
            // Convert character to integer and push onto the stack
            stk.push(ch - '0');
        }
        else
        {
            // Ensure there are at least two elements in the stack for operations
            if (stk.size() < 2) 
            {
                cerr << "Invalid postfix expression" << endl;
                return -1; // or handle error appropriately
            }

            int second = stk.top();
            stk.pop();
            int first = stk.top();
            stk.pop();

            switch (ch)
            {
                case '+':
                    stk.push(first + second);
                    break;
                case '-':
                    stk.push(first - second);
                    break;
                case '*':
                    stk.push(first * second);
                    break;
                case '/':
                    if (second == 0)
                    {
                        cerr << "Division by zero error" << endl;
                        return -1; // or handle error appropriately
                    }
                    stk.push(first / second);
                    break;
                default:
                    cerr << "Unknown operator encountered: " << ch << endl;
                    return -1; // or handle error appropriately
            }
        }
    }

    // The final result should be the only element left in the stack
    if (stk.size() != 1)
    {
        cerr << "Invalid postfix expression" << endl;
        return -1; // or handle error appropriately
    }

    return stk.top();
}

int main()
{
    string postfix = "231*+9-";
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}
