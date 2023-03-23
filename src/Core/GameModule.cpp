//
// Created by patatofour on 21/03/23.
//

#include "GameModule.hpp"
#include "SceneManager.hpp"
#include "SystemManager.hpp"
#include "EntityManager.hpp"
#include "Scene.hpp"
#include "OnClickGraphLib.hpp"
#include "OnClickGameLib.hpp"

Arcade::Core::GameModule::GameModule(const libList &libList)
    : _currentGame({})
    , _sceneManager(nullptr)
{
    for (auto &lib : libList) {
        if (lib.first == LibType::GAME) {
            _libList.push_back(lib);
        }
    }
}

std::unique_ptr<Arcade::Game::ISceneManager> Arcade::Core::GameModule::createMenuScene()
{
    _libList = LibraryHandler::getLibraries();
    
    auto sceneManager = std::make_unique<Arcade::Game::SceneManager>();
    auto systemManager = std::make_unique<Arcade::ECS::SystemManager>();
    auto entityManager = std::make_unique<Arcade::ECS::EntityManager>();

    systemManager->addSystem("onClickGraphLib", new Arcade::Core::OnClickGraphLib());
    systemManager->addSystem("onClickGameLib", new Arcade::Core::OnClickGameLib());
    auto mainMenuScene
        = std::make_unique<Arcade::Game::Scene>(std::move(entityManager), std::move(systemManager));

    sceneManager->registerScene("mainMenu", std::move(mainMenuScene));
    return sceneManager;
}

void Arcade::Core::GameModule::changeGame(const std::string &gameName)
{
    std::unique_ptr<Arcade::Game::ISceneManager> newSceneManager = nullptr;

    if (gameName == "menu") {
        _sceneManager->getCurrentScene()->close();
        _sceneManager = createMenuScene();
        return;
    }

    for (auto &lib : _libList) {
        if (lib.second == gameName) {
            _sceneManager->getCurrentScene()->close();
            newSceneManager = LibraryHandler::loadGameLibrary("./lib/" + lib.second);
            _currentGame = lib;
            _sceneManager = std::move(newSceneManager);
            _sceneManager->getCurrentScene()->init();
            return;
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

Arcade::Game::ISceneManager &Arcade::Core::GameModule::getSceneManager() { return *_sceneManager; }
