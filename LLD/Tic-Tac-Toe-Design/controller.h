#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "playerAbstract.h"
#include "game.h"

class GameController
{
public:
    static void run(Game *game)
    {
        while (1)
        {
            cout << "-New Round-" << endl;
            for (auto &player : game->getPlayers())
            {
                Cell cell = player->makeMove(game->getBoard());
                game->getBoard()->updateBoard(cell);
                game->getBoard()->print();
                auto plyer = game->checkWinner();
                if (plyer != nullptr)
                {
                    cout << "Player with sumbol " << player->getSymbol()->getSymbol() << " Won" << endl;
                    return;
                }
                cout << endl;
                if (game->checkIfPlayable() == false)
                {
                    cout << "No more moves possible" << endl
                         << endl;
                    return;
                }
            }
        }
    }
};
#endif