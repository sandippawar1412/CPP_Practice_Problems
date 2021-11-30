#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H
#include "player.h"

class PlayerFactory
{
public:
    static Human::Builder *createHumanPlayer()
    {
        return Human::getBuilder();
    }

    static Bot::Builder *createBotPlayer()
    {
        return Bot::getBuilder();
    }
};
#endif