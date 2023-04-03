//
// Created by patatofour on 03/04/23.
//

#include "Api.hpp"
#include "MainMenu.hpp"

extern "C" {
Arcade::Game::IGameModule *getGameModule()
{
    return new Arcade::Game::MainMenu();
}

void destroyGameModule(Arcade::Game::IGameModule *gameModule)
{
    delete gameModule;
}

const char *getName()
{
    return "MainMenu";
}

LibType getType()
{
    return GAME;
}
}
