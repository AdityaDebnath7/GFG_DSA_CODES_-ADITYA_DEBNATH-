#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct interval
{
    int start;
    int end;

} range;

bool check(range a, range b)
{
    return a.start < b.start;
}

bool checkoverlap(range a, range b)
{
    if (((b.start >= a.start) && (b.start <= a.end)) || ((b.end >= a.start) && (b.end <= a.end)) || ((b.start <= a.start) && (b.end >= a.end)))
    {
        return true;
    }

    else
        return false;
}

void sortintervals(range interval[], int n)
{
    sort(interval, interval + n, check);
}

int maximumguest(int arrival[], int departure[], int n)

{
    range interval[n]; // creating a tuple type set from arrival and departure data

    for (int i = 0; i < n; i++)
    {
        interval[i].start = arrival[i];
        interval[i].end = departure[i];
    }

    sortintervals(interval, n); // sorting makes life easy

    range temp = {interval[0].start, interval[0].end};
    int res_temp;
    int res = 1;

    if (n != 0)
    {
        res_temp = 1; // for holding temporary number of overlaps
    }
    else
        return 0;

    for (int i = 1; i < n; i++)
    {

        if (checkoverlap(interval[i], temp))
        {
            res_temp++;

            temp = {max(temp.start, interval[i].start), min(temp.end, interval[i].end)}; // shrinking temp to  intersection interval of interval being compared
            res = max(res, res_temp);                                                    // updating result if res_temp gives more than previous
        }

        else
        {
            temp = interval[i];

            res = max(res, res_temp);
            res_temp = 1;
        }
    }
    return res;
}



int main()
{

    int ar[] = {900, 940};
    int dep[] = {1000, 1030};

    cout << maximumguest(ar, dep, 2);

    return 0;
}