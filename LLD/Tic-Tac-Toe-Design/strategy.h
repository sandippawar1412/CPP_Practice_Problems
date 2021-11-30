#ifndef STRATEGY_H
#define STRATEGY_H
#include "board.h"
#include "playerAbstract.h"
#include <bits/stdc++.h>
using namespace std;

class IWinningStrategy
{
public:
    virtual Player *checkWinner(Board *, vector<Player *> &) = 0;
};

class DefaultWinningStratey : public IWinningStrategy
{
public:
    bool checkRows(Board *board, Player *player)
    {
        for (auto &row : board->getBoard())
        {
            bool inRow = true;
            for (auto &cell : row)
            {
                if (cell->getSymbol() == nullptr ||
                    cell->getSymbol() != player->getSymbol())
                {
                    inRow = false;
                    break;
                }
            }
            if (inRow)
                return true;
        }
        return false;
    }

    bool checkCols(Board *board, Player *player)
    {
        auto gameBoard = board->getBoard();
        for (int i = 0; i < board->getCols(); ++i)
        {
            bool inCols = true;
            for (int j = 0; j < board->getRows(); ++j)
            {
                if (gameBoard[j][i]->getSymbol() == nullptr ||
                    gameBoard[j][i]->getSymbol() != player->getSymbol())
                {
                    inCols = false;
                    break;
                }
            }
            if (inCols)
                return true;
        }
        return false;
    }
    bool checkDiag(Board *board, Player *player)
    {
        return false;
    }

    Player *checkWinner(Board *board, vector<Player *> &players)
    {
        for (auto &player : players)
        {
            if (checkRows(board, player) || checkCols(board, player) || checkDiag(board, player))
                return player;
        }
        return nullptr;
    }
};

//avoid updating in functions.. rather return
class IAutoMoveStrategy
{
public:
    // virtual Cell makeMove(Board &board) = 0;
    virtual Cell makeMove(Board *board) = 0;
};

class DefaultMoveStrategy : public IAutoMoveStrategy
{
public:
    // Player *checkWinner(Board board, vector<Player *> players)
    // {
    //     return players.back();
    // }
    // Cell makeMove(Board &board)
    Cell makeMove(Board *board)
    {
        for (auto &row : board->getBoard())
        {
            for (auto &cell : row)
            {
                if (cell->getSymbol() == nullptr)
                    return *cell;
            }
        }
        return new Cell(-1, -1); //no more moves possible
    }
};

#endif