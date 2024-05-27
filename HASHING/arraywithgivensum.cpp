#include <iostream>
using namespace std;
 #include <unordered_set>
 #include <unordered_map>

bool isSum(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++)
    {   
        pre_sum += arr[i];
        if(pre_sum==sum)
            return true;
        if(s.find(pre_sum-sum) != s.end())
          return true;
        s.insert(pre_sum);
    }
    return false;
}

int subArraySum(int arr[], int n, int sum)
    {
        unordered_set<int> s;
         unordered_map<int,int> m;
    long long int pre_sum = 0;
    int res=0;
    
    
    for(int i = 0; i < n; i++)
    {   
        pre_sum += arr[i];
        
        if(pre_sum==sum)
          {  res++;
             
          }
            
        if(s.find(pre_sum-sum) != s.end()){
         // m[pre_sum]++;
          res=res+m[pre_sum-sum];
        if(s.find(pre_sum)==s.end()) { s.insert(pre_sum); m[pre_sum]=1;}
        else m[pre_sum]++;
        }
        else
        { 
        if(s.find(pre_sum)==s.end()) { s.insert(pre_sum); m[pre_sum]=1;}
        else m[pre_sum]++;
        }
    
    }
     return res;
     
    }



int main() {
 
unordered_set<int>h;
cout<<h.empty();


     return 0 ;
}























































































































































































































