#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define r 9
#define c 9
bool isSafe(vector<vector<int>> &sudoku, int sx, int sd, int current)
{
    // to check in column
    for (int i = 0; i < c; i++)
    {
        if (sudoku[sx][i] == current)
            return false;
    }
    // to check in row
    for (int i = 0; i < r; i++)
    {
        if (sudoku[i][sd] == current)
        {
            return false;
        }
    }
    // to check 3x3 matrix  to know the rule is 3xrow/3, 3xcol/3

    int nsi = 3 * (sx / 3);
    int nsj = 3 * (sd / 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[nsi + i][nsj + j] == current)
            {
                return false;
            }
        }
    }
    return true;
}

void fill_sudoku(vector<vector<int>> &sudoku, int sx, int sd, int dx, int dy, int rw, int cl)
{
    if (sx == r)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }

        return;
    }

    //if we are on any column end our row will increase to next and column becomes zero.
    int ns = 0;
    int nd = 0;
    if (sd == sudoku[0].size() - 1)
    {
        ns = sx + 1;
        nd = 0;
    }
    else
    {
        ns = sx;
        nd = sd + 1;
    }
    if (sudoku[sx][sd] != 0)
    {
        // we need not to do anything here as this is already filled, so make the call and
        //give new src and new dst
        fill_sudoku(sudoku, ns, nd, dx, dy, r, c);
    }
    else
    {
        // here you need to fill number from 1 to 9, so will make a loop
        for (int i = 1; i <= 9; i++)
        {
            if (isSafe(sudoku, sx, sd, i))
            {
                sudoku[sx][sd] = i;
                fill_sudoku(sudoku, ns, nd, dx, dy, r, c);
                //backtracking
                sudoku[sx][sd] = 0;
            }
        }
    }
}
void call_sudoku_from_main()
{
    vector<vector<int>> sudoku(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    cout << "going to fill " << endl;
    fill_sudoku(sudoku, 0, 0, r - 1, c - 1, r, c);

    cout << "here is output " << endl;
}