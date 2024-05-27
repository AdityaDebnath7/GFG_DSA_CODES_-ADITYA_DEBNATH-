#include <iostream>
using namespace std;
#include <string>

void computeLPSArray(string pat, int M, int *lps)
{

    // one naive method was to check max lps value to lowest checking one by one then assigning lps to array it was of TIME COMPEXEITY n^3

    lps[0] = 0;
    int t = 0;
    for (int i = 1; i < M; i++)
    {
        if (pat[i] == pat[t])

        {
            t++;
            lps[i] = t;
        }

        else
        {
            if (t != 0)
            {
                i--;
                t = lps[t - 1];
            }
            else
            {
                lps[i] = 0;
            }
        }
    }
}


// Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt)
{
    // Your code here
}

int main()
{

    string txt = "abacabad";int lps[txt.length()];
    computeLPSArray(txt,8,lps);
    for(int i=0;i<txt.length();i++){
        cout<<lps[i]<<" ";
    }

    return 0;
}