// #include<bits/stdc++.h>
// using namespace std;

// int n=6;

// gives correct ans upto 7;

// bool isValid(int i, int j, vector<vector<int>> &grid)
// {
//     if ((i < n && i >= 0) and (j < n && j >= 0) && (grid[i][j] == -1))
//         return true;
//     return false;
// }

// bool fn(vector<vector<int>> &grid, int i, int j, int count)
// {
//     if (count == 35)
//     {
//         grid[i][j] = count;
//         return true;
//     }
//     grid[i][j] = count;

//     if (i - 2 >= 0)
//     {
//         if (isValid(i - 2, j + 1, grid))
//         {
//             if (fn(grid, i - 2, j + 1, count + 1))
//                 return true;
//         }

//         if (isValid(i - 2, j - 1, grid))
//         {
//             if (fn(grid, i - 2, j - 1, count + 1))
//                 return true;
//         }
//     }

//     if (i + 2 < n)
//     {
//         if (isValid(i + 2, j + 1, grid))
//         {
//             if (fn(grid, i + 2, j + 1, count + 1))
//                 return true;
//         }

//         if (isValid(i + 2, j - 1, grid))
//         {
//             if (fn(grid, i + 2, j - 1, count + 1))
//                 return true;
//         }
//     }

//     if (j + 2 < n)
//     {
//         if (isValid(i + 1, j + 2, grid))
//         {
//             if (fn(grid, i + 1, j + 2, count + 1))
//                 return true;
//         }

//         if (isValid(i - 1, j + 2, grid))
//         {
//             if (fn(grid, i - 1, j + 2, count + 1))
//                 return true;
//         }
//     }

//     if (j - 2 >= 0)
//     {
//         if (isValid(i + 1, j - 2, grid))
//         {
//             if (fn(grid, i + 1, j - 2, count + 1))
//                 return true;
//         }

//         if (isValid(i - 1, j - 2, grid))
//         {
//             if (fn(grid, i - 1, j - 2, count + 1))
//                 return true;
//         }
//     }
//     grid[i][j] = -1;
//     return false;
// }


// int main()
// {
//     vector<vector<int>> grid(n, vector<int> (n, -1));
//     grid[0][0] = 0;
//     bool ans = fn(grid, 0, 0, 0); /// i,j,initial count
//     if (!ans) cout << "count not solve";
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; j++)
//             cout << grid[i][j] << " ";
//         cout << "\n";
//     }
//     return 0;
// }



// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
    int sol[N][N];

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Since the Knight is initially at the first block
    sol[0][0] = 0;

    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);

    return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    /* Try all next moves from
    the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                    == 1)
                return 1;
            else

                // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

// Driver Code
int main()
{
    // Function Call
    solveKT();
    return 0;
}

// This code is contributed by ShubhamCoder




















