/*
Nov 19, 21

Zop_Smart: Interview Round 1

A wall is made of two types of bricks, red stone brick and cement brick. 
cement bricks are non porous, and the red stone bricks are porous. 
Only red stone brick allows water to pass through in three directions, 
lower left and lower right diagonals, as well as bottom. 
A wall is said to be safe if the water does reach the ground when it rains. 
The given example is a safe wall. 

Write a program to check if any given wall is safe or not. 
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> off{{1, -1}, {1, 0}, {1, 1}};

bool isValid(int val, int maxVal)
{
    return val >= 0 && val < maxVal;
}

bool dfs(vector<vector<int>> &wall, int r, int c, const int &M, const int &N)
{
    if (r == M - 1)
        return true;

    wall[r][c] = 2; //cement

    for (auto &[ri, ci] : off)
    {
        int nr = r + ri;
        int nc = c + ci;
        if (isValid(nr, M) && isValid(nc, N) && wall[nr][nc] == 0)
        {
            if (dfs(wall, nr, nc, M, N))
            {
                return true;
            }
        }
    }
    return false;
}

void print(vector<vector<int>> wall)
{
    for (auto &row : wall)
    {
        for (auto &ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int M = 6;
    int N = 6;

    vector<vector<int>> wall(M, vector<int>(N, 1));
    wall[0][3] = 0;

    wall[1][2] = 0;
    wall[1][4] = 0;

    wall[2][3] = 0;

    wall[3][2] = 0;
    wall[3][1] = 0;
    wall[3][4] = 0;

    wall[4][2] = 0;
    wall[4][3] = 0;

    // wall[5][3] = 1;
    wall[5][1] = 0;

    bool ans = false;

    print(wall);

    for (int i = 0; i < N; ++i)
    {
        if (wall[0][i] == 0)
            if (ans = dfs(wall, 0, i, M, N))
            {
                break;
            }
    }

    print(wall);

    if (ans)
        cout << "safe" << endl;
    else
        cout << "not safe" << endl;
}