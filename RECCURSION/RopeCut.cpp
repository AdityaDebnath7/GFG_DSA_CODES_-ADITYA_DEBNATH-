#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    int arr[3] = {a, b, c};
     int max = 0;
     for (int i = 0; i < 3; i++)
     {
          if (arr[i] > max)
          {
               max= arr[i];
          }
     }
     return max;
}

int maxCuts(int n, int a, int b, int c)
{
	if(n == 0)
		return 0;
	if(n <= -1)
		return -1;

	int res = max(maxCuts(n-a, a, b, c), 
	          maxCuts(n-b, a, b, c), 
	          maxCuts(n-c, a, b, c));

	if(res == -1)
		return -1;

	return res + 1; 
}

int main()
{
     int a=23;
     cout<<maxCuts(9,2,2,2);

     return 0;
}