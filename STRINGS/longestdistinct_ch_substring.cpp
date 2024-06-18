#include <iostream>
using namespace std;
#include <string>
#include <vector>

const int CHAR = 256;

// int maxarray(vector<int>arr, int n)
// {
//     int sum = arr[0];

//     for (int i = 0; i < n; i++)           // NOT NEEDED ACTUALLY
//     {
//         sum = max(arr[i], sum);
//     }

//     return sum;
// }

int longest_distinct_character_substring(const string &str)
{
    vector<bool> visited(CHAR, false);
    vector<int> length(str.length(), 0);
    length[0] = 1;

    int res = 1;                            // WE MAINTAIN A VISTE DARRAY AND SIZE OF MAX LENGTH POSSIBLE UPTO THAT POINT ARRAY
                                            // WE SEE WHETHER ITS
    int maxi = 1;                             

    visited[str[0]] = true;

    for (int i = 1; i < str.length(); i++)
    {
        if (visited[str[i]] == false)
        {
            length[i] = length[i - 1] + 1;
            maxi = length[i];

            visited[str[i]] = true;
        }

        else
        {
            length[i] = length[i - 1];
        }
    }

    return maxi;
}
int main()
{

    string str = "abcadb";

    cout << longest_distinct_character_substring(str);

    return 0;
}