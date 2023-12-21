#include <iostream>
using namespace std;

int arrkth(int n, int k)
{

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    if ((k) % (n) == 0)
    {
        return arr[n - 1];
    }
    else
    {
        return arr[(k % n) - 1];
    }
}

int jos(int n, int k)
{

    if (n == 1)
    {
        return 0;
    }
    else
        return arrkth(n, (jos(n - 1, k)+(k+1)));
}

int main()
{
    int n ,k;
while(true){
    cout<<"enter n"<<endl;
    cin>>n;
    cout<<"enter k"<<endl;
    cin>>k;cout<<endl;
    cout<<"survivor is "<<jos(n,k)<<endl;
}
   
   

    return 0;
}
