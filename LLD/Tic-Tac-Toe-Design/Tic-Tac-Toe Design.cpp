#include <bits/stdc++.h>
#include "strategy.h"

//should not have attribute public

using namespace std;

// enum Symbol
// {
//     X,
//     O,
// };

class Symbol
{
    char symbol;

public:
    Symbol(char symbol) : symbol(symbol) {}
};

class SymbolRegistry
{
    vector<Symbol *> symbolRegistry;
};

class Player
{
    Symbol *symbol;

public:
    void setSymbol(Symbol *symbol)
    {
        this->symbol = symbol;
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

    static Builder* getBuilder()
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

    static Builder* getBuilder()
    {
        return new Builder;
    }
};

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

/*
if implementing for extensions.. prefer list
*/
class Game
{
    vector<Player *> players;
    Board *board;
    vector<IWinningStrategy *> winningStrategies;
    //write getters setters
public:
    vector<Player *> getPlayers()
    {
        return players;
    }
    vector<IWinningStrategy *> getWinnningStrategies()
    {
        return winningStrategies;
    }
    void setBoard(Board *board)
    {
        this->board = board;
    }

private:
    static class Builder
    {
        Game *game;
        int rows, cols;

    public:
        Builder()
        {
            game = new Game();
        }

        Builder addPlayer(Player *player)
        {
            game->getPlayers().emplace_back(player);
            return *this;
        }

        Builder addWinningStratey(IWinningStrategy *strategy)
        {
            game->getWinnningStrategies().emplace_back(strategy);
            return *this;
        }
        Builder setRows(int rows)
        {
            this->rows = rows;
            return *this;
        }
        Builder setCols(int cols)
        {
            this->cols = cols;
            return *this;
        }

        Game *build()
        {
            if (game->getPlayers().size() < 2)
            {
                //throw exception
            }
            Board *board = new Board(rows, cols);
            game->setBoard(board);
            return game;
        }
    } builder;

public:
    static Builder* getBuilder()
    {
        return new Builder;
    }
};

class DefaultMoveStrategy : public IAutoMoveStrategy
{
public:
    // Player *checkWinner(Board board, vector<Player *> players)
    // {
    //     return players.back();
    // }
    Cell makeMove()
    {
        return Cell(1, 2);
    }
};

int main()
{
    /* if user need to do new Game() its bad design */
    // Game *g = new Game();
    // g->

    Game *game = Game::getBuilder()->addPlayer(Human::getBuilder()->setSymbol('X').build()).addPlayer(Bot::getBuilder()->setSymbol('O').setMoveStrategy(new DefaultMoveStrategy()).build()).build();
}

//Game controller shoudl run
//till all terms end or someone won
//print the display
//if computer's turn, automatically make a move
//else ask input(row, col) from user