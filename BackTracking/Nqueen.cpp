#include <iostream>
using namespace std;

const int N = 1;
int arr[N][N];

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

int queennumber(int arr[][N])
{
    int queen = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1)
            {
                queen++;
            }
        }
    }
    return queen;
}

void board(int arr[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = 0;
        }
    }
}

bool isSafe(int row, int col)
{

    for (int i = 0; i < col; i++) // row attcak by previous queens
        if (arr[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (arr[i][j]) // diagonal from up attack with previous queen
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--) // diagonal from down attack with previous queen
        if (arr[i][j])
            return false;

    return true;
}

bool Nqueen(int col)
{
    if (col == N)
    {
        return true;
    }
    else
    {

        for (int i = 0; i < N; i++)
        {
            if (isSafe(i, col))
            {
                arr[i][col] = 1;

                if (Nqueen(col + 1))
                    return true;
                arr[i][col] =0;
            }
        }
        return false;
    }
}

int main()
{

    board(arr);

    if (Nqueen(0) == true)
    {
        printSolution(arr);
    }

    else cout<<"NO solution";


    return 0;
}