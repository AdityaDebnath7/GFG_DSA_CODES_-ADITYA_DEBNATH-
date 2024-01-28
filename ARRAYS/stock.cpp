#include <iostream>
using namespace std;

/* this is efficient sol naive is in copy*/

int maxprofit(int price[], int n)
{
     int profit = 0;
     int current;
     for (int i = 0; i < n; i++)
     {
          if (price[i + 1] > price[i])
          {

               profit +=  (price[i+1] - price[i]);
          }
     }
     return profit;
}
     int main()
     {

          return 0;
     }