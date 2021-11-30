#ifndef BOARD_H
#define BOARD_H
#include "symbol.h"
#include <bits/stdc++.h>
using namespace std;

class Cell
{
    int x, y;
    Symbol *symbol; //nil or some val
public:
    Cell()
    {
        symbol = nullptr;
    }
    Cell(int x, int y) : x(x), y(y)
    {
        // Cell();
        symbol = nullptr;
    }
    Cell(Cell *cell)
    {
        x = cell->x;
        y = cell->y;
        symbol = nullptr;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    Symbol *getSymbol()
    {
        return symbol;
    }
    void setSymbol(Symbol *symbol)
    {
        this->symbol = symbol;
    }
};

class Board
{
    vector<vector<Cell *>> board;
    int rows, cols;

public:
    Board()
    {
    }
    Board(int rows, int cols) : rows(rows), cols(cols)
    {
        for (int i = 0; i < rows; ++i)
        {
            vector<Cell *> row;
            for (int j = 0; j < cols; ++j)
            {
                row.emplace_back(new Cell(i, j));
            }
            board.emplace_back(row);
        }
    }
    vector<vector<Cell *>> getBoard()
    {
        return board;
    }

    void updateBoard(Cell cell)
    {
        board[cell.getX()][cell.getY()]->setSymbol(cell.getSymbol());
    }
    int getRows()
    {
        return rows;
    }
    int getCols()
    {
        return cols;
    }
    bool isEmptyCellExist()
    {
        for (auto &rows : board)
        {
            for (auto &ele : rows)
            {
                if (ele->getSymbol() == nullptr)
                    return true;
            }
        }
        return false;
    }

    void print()
    {
        for (auto &rows : board)
        {
            for (auto &ele : rows)
            {
                if (ele->getSymbol() == nullptr)
                    cout << "-";

                else
                    cout << ele->getSymbol()->getSymbol();
                cout << " ";
            }
            cout << endl;
        }
    }
};

#endif
