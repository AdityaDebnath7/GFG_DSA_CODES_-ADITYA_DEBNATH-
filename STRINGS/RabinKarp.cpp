#include <iostream>
using namespace std;
#include <string>
#include <cmath>

const int prime = 97; // for taking modulo in hash function
const int dfactor = 5;

int hashstring(string s)
{
    int q = prime;
    int sum = 0;
    int d = 1;

    for (int i = 0; i < s.length(); i++)
    {
        sum += (s[i] * d);
        d *= dfactor;
    }

    return sum;
}

void Rabin_Karp(string text, string pattern)
{  int q= prime;

    int hash_pattern = hashstring(pattern);

    int window_hash = hashstring(text.substr(0, pattern.length() - 1));

    if (text.length() < pattern.length())
    {
        cout << -1;
        return;
    }
    int i = 0;
    bool flag = false;

    for (i; i < text.length() - pattern.length(); i++)
    {
        string prev = text.substr(i, i+1);
        string next = text.substr(i + pattern.length(),i + pattern.length()+1);

        if (window_hash == hash_pattern)
        {
            int j = i;
            for (j; j < pattern.length() + i; i++)
            {

                if (text[j] != pattern[j - i])
                {
                    break;
                }
            }

            if (j == pattern.length() + i)
            {
                cout << i << " ";
                flag = true;
            }
        }

        window_hash = (((window_hash)-hashstring(prev)) / dfactor) + (hashstring(next)) * pow((dfactor), pattern.length() - 1);
    }
     cout<<window_hash<<"  ";
     cout<<hash_pattern<<" ";


    if (flag == false)
    {
        cout << -1;
    }
}

int main()
{


    string s= "geeksforgeeks";
    string pat="eks";
     cout<<s.substr(0,1)<<"  ";

    Rabin_Karp(s,pat);

    return 0;
}