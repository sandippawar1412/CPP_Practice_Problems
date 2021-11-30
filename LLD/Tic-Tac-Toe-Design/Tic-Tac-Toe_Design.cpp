/*
if implementing for extensions.. prefer list

should not have attribute public

if user need to do new Game() its bad design 
    Game *g = new Game();
    
*/

#include <bits/stdc++.h>

#include "game.h"
#include "controller.h"

using namespace std;

int main()
{
    // g->
    // Game *game = Game::getBuilder()->addPlayer(Human::getBuilder()->setSymbol('X').build())
    //                  .addPlayer(Bot::getBuilder()->setSymbol('X').setMoveStrategy(new DefaultMoveStrategy()).build())
    //                  .build();

    Game *game = Game::getBuilder()->addPlayer(
                                       PlayerFactory::createHumanPlayer()
                                           ->setSymbol('X')
                                           .setUser(new User())
                                           .build())
                     .addPlayer(
                         PlayerFactory::createBotPlayer()
                             ->setSymbol('O')
                             .setMoveStrategy(new DefaultMoveStrategy())
                             .build())
                     .addPlayer(
                         PlayerFactory::createBotPlayer()
                             ->setSymbol('P')
                             .setMoveStrategy(new DefaultMoveStrategy())
                             .build())
                     .setRows(3)
                     .setCols(3)
                     .addWinningStratey(new DefaultWinningStratey())
                     .build();

    // game->getBoard()->print();
    GameController controller;
    controller.run(game);
}

//Game controller shoudl run
//till all terms end or someone won
//print the display
//if computer's turn, automatically make a move
//else ask input(row, col) from user