#include <iostream>
using namespace std;

bool palindrome(int x)
{
    int temp = x;
    int rev = 0;
    while (temp != 0)
    {
        int ld = temp % 10;
        rev = (rev*10) + ld;
        temp = temp / 10;
        
    }
    return (x == rev);
}

int main()
{kil:
    cout<<"enter a number";
    int p;
    cin>>p;
    cout<<palindrome(p);
    goto kil;


   
}