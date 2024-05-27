#include <iostream>
using namespace std;

void intersection(int a[], int m, int b[], int n)
{

    int i = 0, j = 0;

    while ((i < m) && (j < n))
    {

        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }

        if (a[i] < b[j])
        {
            i++;
        }

        if (a[i] > b[j])
        {
            j++;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

// i realise that this code fails when we find intersection of two arrays if both of them contains similar element more than once 
// if array are a=[1,1,1,2,2,3] and b=[1,1,2,3] my old code give [1,2,3] but answer should be [1,1,2,3]
//here is modification
/*    while ((i < m) && (j < n))
    {

        if (  (i > 0 && a[i] == a[i - 1]) && (b[j]!=b[j-1])  )     <<<---------   <<<<<<-------------
        {
            i++;
            continue;
        }

        if (a[i] < b[j])
        {
            i++;
        }

        if (a[i] > b[j])
        {
            j++;
        }
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
*/

void Union(int a[], int m, int b[], int n)
{
    int i = 0, j = 0;

    while (1)
    {

        if (i > 0 && (a[i] == a[i - 1]))
        {
            i++;
            continue;
        }
        if ((j > 0) && (b[j] == b[j - 1]))
        {
            j++;
            continue;
        }

        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }

        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }

        if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }

        if (i >= m)
        {
            while (j < n)
            {
                if (b[j] == b[j - 1])
                {
                    j++;
                    continue;
                }

                cout << b[j] << " ";
                j++;
            }

            break;
        }

        if (j >= n)
        {
            while (i < m)
            {

                if (a[i] == a[i - 1])
                {
                    i++;
                    continue;
                }
                cout << a[i] << " ";
                i++;
            }

            break;
        }
    }
}

int main()
{

    int a[] = {1, 2, 3, 4, 5, 5, 5, 7, 7};
    int b[] = {2, 4, 5, 5, 5, 5, 11};

    intersection(a, 9, b, 7);
    cout << endl;
    Union(a, 9, b, 7);

    return 0;
}