#ifndef PLAYER_H
#define PLAYER_H
#include "playerAbstract.h"
#include "strategy.h"
#include "symbol.h"
#include <bits/stdc++.h>
using namespace std;

class Bot : public Player
{
    IAutoMoveStrategy *autoMoveStrategy;

public:
    Cell makeMove(Board *board)
    {
        cout << "Bot with symbol[" << getSymbol()->getSymbol() << "] Played" << endl;
        Cell cell = autoMoveStrategy->makeMove(board);
        cell.setSymbol(getSymbol());
        return cell;
    }
    static class Builder
    {
        Bot *botPlayer;

    public:
        Builder()
        {
            botPlayer = new Bot();
        }

        Bot *build()
        {
            return botPlayer;
        }

        Builder setSymbol(char symbol)
        {
            botPlayer->setSymbol(new Symbol(symbol));
            return *this;
        };

        Builder setMoveStrategy(IAutoMoveStrategy *strategy)
        {
            botPlayer->autoMoveStrategy = strategy;
            return *this;
        }

    } builder;

    static Builder *getBuilder()
    {
        return new Builder();
    }
};

class User
{
    string name;
    string email_id;
};

class Human : public Player
{
    User *user;

public:
    Cell makeMove(Board *board)
    {
        int x, y;
        cout << "For Player with symbol[" << getSymbol()->getSymbol() << "]"
             << " enter cell Nos <x y>: ";
        cin >> x >> y;
        Cell cell(x, y);
        cell.setSymbol(getSymbol());
        return cell;
    }

    static class Builder
    {
        Human *humanPlayer;

    public:
        Builder()
        {
            humanPlayer = new Human();
        }

        Human *build()
        {
            return humanPlayer;
        }

        Builder setUser(User *user)
        {
            humanPlayer->user = user;
            return *this;
        }

        Builder setSymbol(char symbol)
        {
            humanPlayer->setSymbol(new Symbol(symbol));
            return *this;
        };
    } builder;

    static Builder *getBuilder()
    {
        return new Builder();
    }
};

#endif
