#include <iostream>
using namespace std;
#include <queue>
#include <vector>

void kclosest(int arr[], int n, int x, int k)
{

    pair<int, int> p[n];

    for (int i = 0; i < n; i++)
    {
        p[i] = {abs(arr[i] - x), i};
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq(p, p + n);

    int i = 0;
    while (!pq.empty() && i < k)
    {

        cout<<arr[pq.top().second]<<" , ";
        pq.pop();
        i++;
        

    }
}

int main()
{




    int arr[]={10,20,2,30,35,45,50};
    kclosest(arr,7,1,3);


    return 0;
}