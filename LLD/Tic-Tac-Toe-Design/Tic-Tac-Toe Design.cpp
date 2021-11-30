#include <bits/stdc++.h>
#include "strategy.h"
#include "board.h"
#include "player.h"

//should not have attribute public

using namespace std;

// enum Symbol
// {
//     X,
//     O,
// };

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

    // private:
    // static class Builder
    class Builder
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
            // game->getPlayers().emplace_back(player);
            game->players.emplace_back(player);
            return *this;
        }

        Builder addWinningStratey(IWinningStrategy *strategy)
        {
            // game->getWinnningStrategies().emplace_back(strategy);
            game->winningStrategies.emplace_back(strategy);
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

            unordered_set<char> st;
            for (auto &player : game->getPlayers())
            {
                char ch = player->getSymbol()->getSymbol();
                if (st.count(ch))
                {
                    //throw exception: DuplicateSymbolExist
                }
                else
                {
                    st.emplace(ch);
                }
            }

            Board *board = new Board(rows, cols);
            // game->setBoard(board);
            game->board = board;
            return game;
        }
    }; // builder;

public:
    static Builder *getBuilder()
    {
        return new Builder();
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