#include <iostream>
using namespace std;
#include <unordered_set>
#include <unordered_map>

int longest_sub_arraywithsum(int arr[], int n, int sum)
{
    int res = 0;    /// holds temporay length of array with given sum
    int resmax = 0; /// holds maximum temporay length of array with given sum upto ith iteration
    int pre_sum = 0;

    unordered_set<int> s;      // hold already occured presums
    unordered_map<int, int> m; // map already occured presum where it actually occured to the position of i  so that it give that

    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if (pre_sum == sum) // if presum == sum then it means array from index to i is equal to that sum length of subarry is i+1
        {
            res = i + 1;
            resmax = max(resmax, res);
        }

        if (s.find(pre_sum - sum) != s.end()) // if presum-sum found already then it means we got some subarry having that sum

        {

            for (auto x : m)
            { // increment length of all previous size by one in map before we insert new value to map with value 1 or increment of 1
                m[x.first]++;
            }

            res = m[pre_sum - sum];
            resmax = max(resmax, res);

            if (s.find(pre_sum) == s.end())
            {
                s.insert(pre_sum);
                m[pre_sum] = 1;
            }
            else
                m[pre_sum]++;
        }

        else
        {                   // corresponding else /.....

            for (auto x : m)
            {
                m[x.first]++;
            }

            if (s.find(pre_sum) == s.end())
            {
                s.insert(pre_sum);
                m[pre_sum] = 1;
            }
            else
                m[pre_sum]++;
        }
    }
    return res;
}

int main()
{



int arr[]={5,8,-4,-4,9,-2,2};
cout<<longest_sub_arraywithsum(arr,7,0);
int brr[]={8,3,7};
cout<<longest_sub_arraywithsum(brr,3,15);
    return 0;
}