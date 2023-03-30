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

Arcade::Graph::IDisplayModule *getDisplayModule()
{
    return nullptr;
}

void destroyGameModule(Arcade::Game::IGameModule *gameModule)
{
    free(gameModule);
}

void destroyDisplayModule([[maybe_unused]] Arcade::Graph::IDisplayModule *displayModule)
{
}

const char *getName()
{
    return "Test game";
}

LibType getType()
{
    return GAME;
}
