#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

// void primefac(int n)
// {
//     int x = n;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (isPrime(i))
//         {

//             while (x % i == 0)
//             {
//                 cout << i << ";";
//                 x = x / i;
//             }
//         }
//     }
//     if (x > 1)
//     {
//         cout << x << endl;
//     }}

void printPrimeFactors(int n)
{
	if(n <= 1)
		return;

	while(n % 2 == 0)
	{
		cout<<2<<" ";

		n = n / 2;
	}

	while(n % 3 == 0)
	{
		cout<<3<<" ";

		n = n / 3;
	}

	for(int i=5; i*i<=n; i=i+6)
	{
		while(n % i == 0)
		{
			cout<<i<<" ";

			n = n / i;
		}

		while(n % (i + 2) == 0)
		{
			cout<<(i + 2)<<" ";

			n = n / (i + 2);
		}
	}

	if(n > 3)
		cout<<n<<" ";

	cout<<endl;
}

int main() {
    
    	int n = 450;
    	
    	printPrimeFactors(n);
    	
    	return 0;
}

int main()

{
    int t = 1;
	int c= log10(200);
    int q;

    while (t <= 3)
    {
        cout << "Enter a number";
        cin >> q;
       printPrimeFactors(q);
        t++;
    }
    return 0;
}