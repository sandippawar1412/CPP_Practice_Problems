#ifndef STRATEGY_H
#define STRATEGY_H

#include <bits/stdc++.h>
using namespace std;

class Player;
class Board;
class Cell;

class IWinningStrategy
{
public:
    virtual Player *checkWinner(Board, vector<Player *>) = 0;
};

//avoid updating in functions.. rather return
class IAutoMoveStrategy
{
public:
    virtual Cell makeMove() = 0;
};

#endif