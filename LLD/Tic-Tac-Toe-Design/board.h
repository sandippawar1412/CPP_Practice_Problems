#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h>
using namespace std;

class Symbol;

class Cell
{
    int x, y;
    Symbol *symbol; //nil or some val
public:
    Cell()
    {
        symbol = nullptr;
    }
    Cell(int x, int y) : x(x), y(y) {}
};

class Board
{
    vector<vector<Cell *>> board;

public:
    Board()
    {
    }
    Board(int rows, int cols)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                board[i].emplace_back(new Cell(i, j));
            }
        }
    }
};

#endif
