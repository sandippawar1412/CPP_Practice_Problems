#ifndef PLAYER_ABSTRACT_H
#define PLAYER_ABSTRACT_H

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
    virtual Cell makeMove(Board *board) = 0;

    class Builder
    {
    };
};

#endif