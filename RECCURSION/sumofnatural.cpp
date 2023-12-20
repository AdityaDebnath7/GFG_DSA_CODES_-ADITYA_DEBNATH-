#include <iostream>
using namespace std;

int sumnatural(int n){
    if (n==1)
    {
        return 1;
    }
    else return n+sumnatural(n-1);
}
int main() {
 
int a= 5;
cout<<sumnatural(a);
    
     return 0 ;
}