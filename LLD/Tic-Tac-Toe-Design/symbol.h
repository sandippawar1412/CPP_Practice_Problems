#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol
{
    char symbol;

public:
    char getSymbol()
    {
        return symbol;
    }

    Symbol(char symbol) : symbol(symbol) {}
};

class SymbolRegistry
{
    vector<Symbol *> symbolRegistry;
};

#endif