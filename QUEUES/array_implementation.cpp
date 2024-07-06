#include <iostream>
using namespace std;

class queue
{  public:

    int size;
    int *arr;
    int front;
    int rear;

    queue(int n)
    {
        size = n;
        arr = new int[size];
        int front = 0;
        int rear = -1;
    }

    void enqueue(int x)
    {
        if (abs(rear - front) == size - 1)
            cout << "space full";

        else
        {
            rear = (rear + 1) % size;

            arr[rear] = x;
        }
    }

    int dequeue()
    {
        if (front - 1 == rear)
        {
            cout << "error in dequeuing";
        }
        int temp = front;
        front = (front + 1) % size;

        return arr[temp];
    }

    int size()
    {
        if (rear == -1 || front-rear)
            return 0;
        else
        {

            return abs(rear - front) + 1;
        }
    }

    bool isempty()
    {
        if (rear == -1)
            return true;
        else if (front - rear == 1)
            return true;
        else
            return false;
    }


};

int main()
{
    queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout<<q.dequeue();
    cout<<q.dequeue();
    


    return 0;
}