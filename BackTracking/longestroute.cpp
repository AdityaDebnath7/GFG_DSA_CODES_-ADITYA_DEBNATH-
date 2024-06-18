#include <iostream>
using namespace std;
#include <vector>

// i need to find the length of longest path

bool isSafe(int i, int j, vector<vector<int>> maze)
{
     if (maze[i][j] == 1)
     {
          return true;
     }
     return false;
}

bool isblocked(int i, int j, vector<vector<int>> maze)
{
     if (i + 1 < maze.size() && i >= 0 && j < maze[0].size() && j >= 0 && isSafe(i + 1, j, maze)) // if it can go down
     {
          return false;
     }

     if (j - 1 >= 0 && j < maze[0].size() && i >= 0 && i < maze.size() && isSafe(i, j - 1, maze)) // if it can go left
     {
          return false;
     }

     if (i - 1 >= 0 && i < maze.size() && j < maze[0].size() && j >= 0 && isSafe(i - 1, j, maze)) // if it can go up
     {
          return false;
     }

     if (j + 1 < maze[0].size() && j >= 0 && i >= 0 && i < maze.size() && isSafe(i, j + 1, maze)) // if it can go right
     {
          return false;
     }

     return true;
}

int res = 0;

int longest_path(vector<vector<int>> maze, int i, int j, int count)
{
     if (isblocked(i, j, maze))
     {
          res = max(res, count);

     }

     else
     {

          if (isSafe)
          {
               maze[i][j] = 0;
               count++;

              if(j-1>=0) longest_path(maze, i, j - 1, count);
              

               if(j<maze[0].size()-1)longest_path(maze, i, j + 1, count);
              
              if(i+1<maze.size()) longest_path(maze, i + 1, j, count);
               
              if(i-1>=0) longest_path(maze, i - 1, j - 1, count);
              
               count--;
               maze[i][j] = 1;
          }
          
     }

     return res;
}

int main()
{

     vector<vector<int>> mat = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };


     cout<<longest_path(mat,0,0,0);

     return 0;
}