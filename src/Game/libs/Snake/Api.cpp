/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** api
*/

#include "Api.hpp"
#include "SnakeGameModule.hpp"

extern "C" {
    Arcade::Game::IGameModule *getGameModule()
    {
        return new Snake::SnakeGameModule();
    }

    void destroyGameModule(Arcade::Game::IGameModule *gameModule)
    {
        free(gameModule);
    }

    const char *getName()
    {
        return "Snake";
    }

    LibType getType()
    {
        return GAME;
    }
}
