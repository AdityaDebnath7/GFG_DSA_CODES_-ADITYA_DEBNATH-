#include <iostream>
using namespace std;
#include <vector>
const int size = 3;
const int N = 4;

bool ratmaze(int arr[size][size], int i, int j) // binary maze to tell whether rat can reach end or not starting from indext 0,0 to final n-1,n-1
{
    if (i == 0 && j == 0 && arr[0][0] == 0)
    { // I THINK MY SOLUTION IS ALSO BETTER
        return false;
    }

    if (i == size - 1 && j == size - 1)
    {
        return true;
    }

    else
    {
        if (arr[i + 1][j] == 1)
        {
            return ratmaze(arr, i + 1, j);
        }
        if (arr[i][j + 1] == 1)
        {
            return ratmaze(arr, i, j + 1);
        }
    }

    return false;
}

///////Using BACKTRACKING WE INTRODUCE IsSAFE CONDITION BEFORE MAKING A RECURSIVE CALL
// SO AS TO REDUCE THE RECURSIVE CALL THAT ARE NOT GONNA LEAD TO THE SOLUTION

bool solveMazeRec( // declaration
    int maze[N][N], int x,
    int y, int sol[N][N]);

void printSolution(int sol[N][N])
{ /// prints solution array
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[N][N], int i, int j) // checks wheather the current cell is safe to stand or not
{
    return (i < N && j < N && maze[i][j] == 1);
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0}, // initialise soltion array all to zero
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMazeRec(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol);
    return true;
}

// ACTUAL CODE FOR FINDING ROUTE
//  I AND J ARE THE INDEX ON WHICH RAT STANDS INITIALLLY

bool solveMazeRec(int maze[N][N], int i, int j, int sol[N][N])
{
    if (i == N - 1 && j == N - 1 && maze[i][j] == 1)
    { // DESTINATION REACHED CONDITION
        sol[i][j] = 1;
        return true;
    }

    if (isSafe(maze, i, j) == true)
    { // CHECKING IF SAFE TO STAND
        sol[i][j] = 1;    

        if (solveMazeRec(maze, i + 1, j, sol) == true)
            return true; // RECURSIVE CALL TO ONE DOWN STEP

        if (solveMazeRec(maze, i, j + 1, sol) == true) // RECURSIVE CALL TO ONE RIGHT STEP
            return true;

        sol[i][j] = 0; // IF NOT FOUND TRUE FROM ANY PATH THEN THAT CELL MARKED ZERO
    }

    return false;
}

int main()
{
    int arr[3][3] = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};

    cout << ratmaze(arr, 0, 0);

    return 0;
}