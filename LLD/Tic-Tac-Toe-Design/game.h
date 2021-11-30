#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h>

#include "board.h"
#include "player.h"
#include "playerFactory.h"
#include "strategy.h"

using namespace std;

class Game
{
    vector<Player *> players;
    Board *board;
    vector<IWinningStrategy *> winningStrategies;
    //write getters setters
public:
    Board *getBoard()
    {
        return board;
    }
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

    Player *checkWinner()
    {
        for (auto &startegy : getWinnningStrategies())
        {
            //for now, return result of first strategy
            return startegy->checkWinner(board, players);
        }
        return nullptr;
    }

    bool checkIfPlayable()
    {
        return board->isEmptyCellExist();
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
            rows = 3;
            cols = 3;
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
                cout << "Players < 2" << endl;
                //throw exception
            }

            unordered_set<char> st;
            for (auto &player : game->getPlayers())
            {
                char ch = player->getSymbol()->getSymbol();
                if (st.count(ch))
                {
                    //throw exception: DuplicateSymbolExist
                    cout << "Multiple players using same symbol" << endl;
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

#endif