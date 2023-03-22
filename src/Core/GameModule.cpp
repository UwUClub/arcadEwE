//
// Created by patatofour on 21/03/23.
//

#include "GameModule.hpp"

Arcade::Core::GameModule::GameModule(const libList &libList) : _currentGame({})
{
    for (auto &lib : libList) {
        if (lib.first == LibType::GAME) {
            _libList.push_back(lib);
        }
    }
}

void Arcade::Core::GameModule::changeGame(const std::string &gameName)
{
    std::unique_ptr<Arcade::Game::ISceneManager> newSceneManager = nullptr;

    for (auto &lib : _libList) {
        if (lib.second == gameName) {
            _sceneManager->getCurrentScene()->close();
            newSceneManager
                = LibraryHandler::loadGameLibrary("./lib/" + lib.second);
            _currentGame = lib;
            _sceneManager = std::move(newSceneManager);
            _sceneManager->getCurrentScene()->init();
            break;
        }
    }
}

void Arcade::Core::GameModule::changeGame()
{
    std::unique_ptr<Arcade::Game::ISceneManager> newSceneManager = nullptr;
    auto it = _libList.begin();

    for (; it != _libList.end(); ++it) {
        if (it->second == _currentGame.second) {
            break;
        }
    }
    if (it == _libList.end()) {
        it = _libList.begin();
    }
    _sceneManager->getCurrentScene()->close();
    newSceneManager = LibraryHandler::loadGameLibrary("./lib/" + it->second);
    _currentGame = *it;
    _sceneManager = std::move(newSceneManager);
    _sceneManager->getCurrentScene()->init();
}

Arcade::Game::ISceneManager &Arcade::Core::GameModule::getSceneManager()
{
    return *_sceneManager;
}
