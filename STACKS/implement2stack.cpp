#include <iostream>
using namespace std;

class twostack
{
public:
    int *arr;
    int cap1;
    int cap2;
    int size;

    twostack(int n)
    {
        arr = new int[n];
        cap1 = -1;
        cap2 = n;
        size = n;
    }

    void push1(int x)
    {

        if (cap1 < cap2 - 1 && cap1 < size - 1)
        {
            cap1++;
            arr[cap1] = x;
        }
        else
            cout << "space error1";
    }

    void push2(int x)
    {

        if (cap2 > cap1 + 1 && cap2 > 0)
        {
            cap2--;
            arr[cap2] = x;
        }
        else
            cout << "space error1";
    }

    void pop1()
    {
        if (cap1 > -1)
        {
            cap1--;
        }
        else
            cout << "space error2";
    }

    void pop2()
    {

        if (cap2 < size)
        {
            cap2++;
        }
        else
            cout << "space errror2";
    }

    int size1()
    {
        return cap1 + 1;
    }
    int size2()
    {
        return size - cap2;
    }

    int top1()
    {
        if (cap1 > -1)
            return arr[cap1];
    }

    int top2()
    {
        if (cap2 < size)
            return arr[cap2];
    }
};

int main()
{

    twostack ts(10);

    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push1(4);
    ts.push2(10);
    ts.push2(9);
    ts.push2(8);
  
   cout<<ts.top1();
   


    return 0;
}