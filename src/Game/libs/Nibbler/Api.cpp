/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** api
*/

#include "Api.hpp"
#include "NibblerGameModule.hpp"

extern "C" {
    Arcade::Game::IGameModule *getGameModule()
    {
        return new Nibbler::NibblerGameModule();
    }

    void destroyGameModule(Arcade::Game::IGameModule *gameModule)
    {
        free(gameModule);
    }

    const char *getName()
    {
        return "Nibbler";
    }

    LibType getType()
    {
        return GAME;
    }
}
