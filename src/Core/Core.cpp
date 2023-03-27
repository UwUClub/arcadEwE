//
// Created by patatofour on 20/03/23.
//

#include "Core.hpp"

#include <memory>
#include "EventManager.hpp"
#include "Component.hpp"

Arcade::Core::Core::Core()
    : _gameModule(nullptr)
{
    auto libs = LibraryFinder::getLibraries();

    for (auto &lib : libs) {
        if (lib.first == LibType::GRAPH) {
            _currentDisplayModule = lib.second;
            break;
        }
    }

    _displayModule = std::make_unique<DisplayHandler>(_currentDisplayModule);
    _eventManager = std::make_unique<ECS::EventManager>();
}

void Arcade::Core::Core::run()
{
    //    while (_eventManager->isEventTriggered("QUIT").first) {
    //        auto &gameSys = _gameModule->getSceneManager().getCurrentScene()->getSystemManager();
    //        auto &displaySys = _displayModule->getSystemManager();
    //
    //        gameSys.update(0, *_eventManager, *_displayModule, *_gameModule);
    //        displaySys.update(0, *_eventManager, *_displayModule, *_gameModule);
    //        handleCoreEvents();
    //        _eventManager->clearEvents();
    //    }
}

void Arcade::Core::Core::handleCoreEvents()
{
    auto event = _eventManager->isEventTriggered("CHANGE_GAME");

    if (event.first) {
        for (auto &comp : *event.second) {
            if (comp.has_value()) {
                std::string gameName = comp.value()->id;
                loadGameModule(gameName);
                continue;
            }
            loadGameModule();
        }
    }
    event = _eventManager->isEventTriggered("CHANGE_LIB");
    if (event.first) {
        for (auto &comp : *event.second) {
            if (comp.has_value()) {
                std::string libName = comp.value()->id;
                loadDisplayModule(libName);
                continue;
            }
            loadDisplayModule();
        }
    }
}

void Arcade::Core::Core::loadGameModule(const std::string &path)
{
    _currentGameModule = path;
    _gameModule = std::make_unique<GameHandler>(path);
}

void Arcade::Core::Core::loadGameModule()
{
    auto list = LibraryFinder::getLibraries();
    auto it = list.begin();

    for (; it != list.end(); ++it) {
        if (it->second == _currentGameModule) {
            break;
        }
    }
    if (it == list.end()) {
        it = list.begin();
    }
    _gameModule = std::make_unique<GameHandler>("./lib/" + it->second);
    _currentGameModule = it->second;
}

void Arcade::Core::Core::loadDisplayModule(const std::string &path)
{
    _currentDisplayModule = path;
    _displayModule = std::make_unique<DisplayHandler>(path);
}

void Arcade::Core::Core::loadDisplayModule()
{
    auto list = LibraryFinder::getLibraries();
    auto it = list.begin();

    for (; it != list.end(); ++it) {
        if (it->second == _currentDisplayModule) {
            break;
        }
    }
    if (it == list.end()) {
        it = list.begin();
    }
    _displayModule = std::make_unique<DisplayHandler>("./lib/" + it->second);
    _currentDisplayModule = it->second;
}
