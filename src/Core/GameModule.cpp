//
// Created by patatofour on 21/03/23.
//

#include "GameModule.hpp"

Arcade::Core::GameModule::GameModule(libList &libList)
    : _libList(libList)
{
}

bool Arcade::Core::GameModule::changeGame(const std::string &gameName)
{
    return false;
}

Arcade::Game::ISceneManager &Arcade::Core::GameModule::getSceneManager()
{
    return *_sceneManager;
}
