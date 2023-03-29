/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Api to access the lib in .so files
*/

#include "Api.hpp"
#include "TestGame.hpp"

Arcade::Game::IGameModule *getGameModule()
{
    return new Arcade::Game::TestGame();
}

void destroyGameModule(Arcade::Game::IGameModule *gameModule)
{
    free(gameModule);
}

const char *getName()
{
    return "Test game";
}

LibType getType()
{
    return GAME;
}
