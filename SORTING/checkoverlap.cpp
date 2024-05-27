#include <iostream>
#include <algorithm>
using namespace std;

typedef struct interval
{
    int start;
    int end;

} range;

bool check(range a, range b) // logic for sorting interval on the basis of their start value
{
    return a.start < b.start;
}
bool checkoverlap(range a, range b) // to check whether two set overlap or not
{
    if (((b.start >= a.start) && (b.start <= a.end)) || ((b.end >= a.start) && (b.end <= a.end)) || ((b.start <= a.start) && (b.end >= a.end)))
    {
        return true;
    }

    else
        return false;
}

void sortintervals(range interval[], int n) // sorting interval array on the basis of their start values

{
    sort(interval, interval + n, check);
}

void mergeintervals(range interval[], int n) // merging them and printing them without deleting any element from the array
{
    sortintervals(interval, n);

    int m = 0;
    range temp = {interval[m].start, interval[m].end}; // to hold temporary combined set

    for (int i = 1; i < n; i++)
    {

        if (checkoverlap(interval[i], temp))
        {
            temp = {min(interval[i].start, temp.start), max(interval[i].end, temp.end)};
            if (i == n - 1) // for tackling when the last element comes edge case
            {
                cout << "{ " << temp.start << "," << temp.end << "} ";
            }
        }

        else
        {

            cout << "{ " << temp.start << "," << temp.end << "} ";
            temp = interval[i];

            if (i == n - 1) // for tackling when the last element comes edge case
            {
                cout << "{ " << interval[i].start << "," << interval[i].end << "} ";
            }
        }
    }
}

int main()
{

    range inter[] = {{1, 4}, {20, 100}, {12, 14}, {13, 15}, {4, 10}};
    mergeintervals(inter, 5);
    // inter will get sorted in origional array after this
    int i = 0;
    while (i < 5)
    {
        cout << inter[i].start << "," << inter[i].end << endl;
        i++;
    }

    return 0;
}