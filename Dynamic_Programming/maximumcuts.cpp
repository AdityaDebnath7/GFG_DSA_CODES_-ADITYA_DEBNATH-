#include <iostream>
using namespace std;


int res=0;


int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n==0)return res;
        if(n<0)return 0;


        else
        {

          return maximizeTheCuts(n-z,x,y,z)+1;

          return maximizeTheCuts(n-y,x,y,z)+1;

          return maximizeTheCuts(n-x,x,y,z)+1;


        }
    }
int main() {
  cout<<maximizeTheCuts(4,2,1,1);
  

     return 0 ;
}