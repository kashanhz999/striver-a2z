/*
===============================================================================
 07 - 2D ARRAYS (MATRIX)
===============================================================================
 No input needed.

 A 2D array is an "array of arrays" - a grid with rows and columns.

     int mat[3][4];      // 3 rows, 4 columns

              col0 col1 col2 col3
     row 0  [  1    2    3    4  ]
     row 1  [  5    6    7    8  ]
     row 2  [  9   10   11   12  ]

     mat[1][2] = 7   ->  mat[row][col]

 In memory it's stored ROW BY ROW in one straight line ("row-major"):
     1 2 3 4 5 6 7 8 9 10 11 12
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

const int R = 3, C = 4;

// When passing a 2D array, the number of COLUMNS must be given in the type.
void printMatrix(int mat[][C], int rows)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < C; j++) {
            cout << setw(3) << mat[i][j];   // setw(3) = print in a 3-wide column (alignment)
        }
        cout << "\n";
    }
}

int main()
{
    // ---------------------------------------------------------------
    // 1. Declare + initialise
    // ---------------------------------------------------------------
    int mat[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int zeros[2][2] = {};            // all zeros

    cout << "mat[1][2] = " << mat[1][2] << "\n";   // 7
    cout << "zeros[1][1] = " << zeros[1][1] << "\n";

    // Update a value
    mat[0][1] = 14;                  // (this is what the old version of this file did)
    cout << "after mat[0][1] = 14:\n";
    printMatrix(mat, R);
    mat[0][1] = 2;                   // put it back

    // ---------------------------------------------------------------
    // 2. Reading a matrix from input (pattern)
    // ---------------------------------------------------------------
    //   int r, c; cin >> r >> c;
    //   int m[100][100];
    //   for (int i = 0; i < r; i++)
    //       for (int j = 0; j < c; j++)
    //           cin >> m[i][j];

    // ---------------------------------------------------------------
    // 3. Row sums and column sums
    // ---------------------------------------------------------------
    for (int i = 0; i < R; i++) {
        int rowSum = 0;
        for (int j = 0; j < C; j++) rowSum += mat[i][j];
        cout << "row " << i << " sum = " << rowSum << "\n";
    }
    for (int j = 0; j < C; j++) {                 // column loop OUTSIDE
        int colSum = 0;
        for (int i = 0; i < R; i++) colSum += mat[i][j];
        cout << "col " << j << " sum = " << colSum << "\n";
    }

    // ---------------------------------------------------------------
    // 4. Transpose - rows become columns: t[j][i] = mat[i][j]
    //    A 3x4 matrix becomes 4x3.
    // ---------------------------------------------------------------
    int t[C][R];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            t[j][i] = mat[i][j];

    cout << "transpose:\n";
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) cout << setw(3) << t[i][j];
        cout << "\n";
    }

    // ---------------------------------------------------------------
    // 5. Diagonals of a square matrix (n x n)
    //    primary diagonal:   i == j
    //    secondary diagonal: i + j == n - 1
    // ---------------------------------------------------------------
    int sq[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int primary = 0, secondary = 0;
    for (int i = 0; i < 3; i++) {
        primary += sq[i][i];
        secondary += sq[i][3 - 1 - i];
    }
    cout << "primary diagonal sum = " << primary << ", secondary = " << secondary << "\n";

    // TIP: in DSA you'll mostly use  vector<vector<int>> grid(rows, vector<int>(cols, 0));
    // because its size can be decided at runtime. (See 03-STL/02-vector.cpp)

    return 0;
}

/*
 EXPECTED OUTPUT:
 mat[1][2] = 7
 zeros[1][1] = 0
 after mat[0][1] = 14:
   1 14  3  4
   5  6  7  8
   9 10 11 12
 row 0 sum = 10
 row 1 sum = 26
 row 2 sum = 42
 col 0 sum = 15
 col 1 sum = 18
 col 2 sum = 21
 col 3 sum = 24
 transpose:
   1  5  9
   2  6 10
   3  7 11
   4  8 12
 primary diagonal sum = 15, secondary = 15
*/
