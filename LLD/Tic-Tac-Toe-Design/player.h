#ifndef PLAYER_H
#define PLAYER_H

#include "strategy.h"
#include "symbol.h"
#include <bits/stdc++.h>
using namespace std;

class Player
{
    Symbol *symbol;

public:
    void setSymbol(Symbol *symbol)
    {
        this->symbol = symbol;
    }
    Symbol *getSymbol()
    {
        return symbol;
    }

    class Builder
    {
    };
};

class Bot : public Player
{
    IAutoMoveStrategy *autoMoveStrategy;

public:
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
    User user;

public:
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

        Builder setUser(User user)
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
