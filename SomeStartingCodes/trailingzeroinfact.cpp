#include <iostream>
using namespace std;

// int fact(int n){
//     int rev=1;
//     for ( int i = 2; i <=n; i++)
//     {
//         rev= rev *i;
//     }
//     return rev;
//}
int count(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i = i * 5)
    {
        res = (res + (n / i));
    }
    return res;
}
int main()
{
kil:
    // int a,b,c=0;

    //     cout<<"enter no.";
    //     cin>>a;
    //      b= fact(a);

    //     while ((b%10)==0)
    //     {
    //       c++;
    //       b=b/10;

    //     }
    //     cout<<c;
    //     goto kil;
    int a;
    cout << "enter number";
    cin >> a;
    cout << count(a);

    return 0;
}