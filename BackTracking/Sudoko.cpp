#include <iostream>
using namespace std;

const int N = 9;
const int RootN = 3;

int arr[N][N] = {{0, 7, 2, 6, 0, 0, 0, 0, 0},
                 {0, 0, 5, 8, 0, 9, 2, 0, 6},
                 {0, 0, 0, 0, 0, 0, 0, 7, 0},
                 {8, 0, 9, 0, 2, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0, 0, 0, 4},
                 {0, 0, 0, 0, 1, 0, 7, 0, 9},
                 {0, 5, 0, 0, 0, 0, 0, 0, 0},
                 {2, 0, 3, 1, 0, 7, 6, 0, 0},
                 {0, 0, 0, 0, 0, 5, 1, 4, 0}};

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}


bool isSafe(int num, int row, int col)
{

    for (int i = 0; i < N; i++)
    {
        if (arr[row][i] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i][col] == num)
        {
            return false;
        }
    }

    int subsquaretop;

    switch (row / 3)
    {
    case 0:
        subsquaretop = 0;
        break;
    case 1:
        subsquaretop = 3;
        break;

    case 2:
        subsquaretop = 6;
        break;

    }

    for (int i = subsquaretop; i < subsquaretop + 3; i++)
    {
        for (int j = subsquaretop; j < subsquaretop + 3; j++)
        {
            if (arr[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool fillSudoku()
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (arr[i][j] == 0)
            {
                break;
            }
        }
    }

    if (i == N && j == N)
    {
        return true;
    }

    for (int x = 1; x <= N; x++)
    {
        if (isSafe(x, i, j))
        {
            arr[i][j] = x;
            if (fillSudoku())
                return true;
            arr[i][j] = 0;
        }
    }

    return false;
}

int main()
{

    fillSudoku();

    for (int i = 0; i < N; i++)
    {
       for (int j = 0; j < N; j++)
       {
         cout<<arr[i][j]<<" ";
       }
       cout<<endl;
       
    }
    
    

    return 0;
}