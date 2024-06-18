#include <iostream>
using namespace std;
#include <stack>
#include <vector>



vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res(n);
       
       stack<pair<int,int>> s;
       
       res[0]=1;
       s.push(make_pair(price[0],0));
       
       int i=1;
       
       while(i<n)
       {  
           
           while(!(s.empty())&& s.top().first<=price[i]  )
           {
               s.pop();
               
           }
           
           if(s.empty()) res[i]=i+1;
           else {res[i]= i- (s.top().second);}
           
           s.push(make_pair(price[i],i));
           
           i++;
           
           
       }
       
       return res;
       
    }

int main() {
 

     return 0 ;
}