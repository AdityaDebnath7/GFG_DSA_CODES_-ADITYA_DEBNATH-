#include <iostream>
using namespace std;
#include <queue>

int main()
{

    priority_queue<int> pq;
    pq.push(1);
    pq.push(10);

    pq.push(3);

    pq.push(5);

    while (!pq.empty())
    {
        cout << pq.top() << endl;

        pq.pop();
    }

    return 0;
}