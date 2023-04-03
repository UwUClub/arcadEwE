//
// Created by patatofour on 20/03/23.
//

#include <memory>
#include "Core.hpp"
#include "EventManager.hpp"
#include "Component.hpp"
#include "Events.hpp"
#include "MainMenu.hpp"
#include "Text.hpp"

Arcade::Core::Core::Core(const std::string &pathDisplay)
    : _gameModule(nullptr)
    , _mainMenu(std::make_unique<Arcade::Game::MainMenu>())
    , _clock(std::make_unique<Arcade::Core::Clock>())
{
    auto libs = LibraryFinder::getLibraries();

    if (pathDisplay.empty()) {
        for (auto &lib : libs) {
            if (lib.first == LibType::GRAPH) {
                _currentDisplayModule = lib.second;
                break;
            }
        }
    } else {
        _currentDisplayModule = pathDisplay;
    }

    // std::cout << "display module path: " << _currentDisplayModule << std::endl;
    // std::cout << "game module path: " << _currentGameModule << std::endl;
    //_gameModule = std::make_unique<GameHandler>(_currentGameModule);
    _displayModule = std::make_unique<DisplayHandler>(_currentDisplayModule);
    _eventManager = std::make_unique<ECS::EventManager>();
}

void Arcade::Core::Core::update()
{
    while (!_eventManager->isEventTriggered(QUIT).first) {
        // if (_gameModule)
        //     _gameModule->operator->()->update(0, *_eventManager);
        // else
        _mainMenu->update(0, *_eventManager);
        handleCoreEvents();
        auto &currentEntityManager = _mainMenu->getCurrentEntityManager();

        _eventManager->clearEvents();
        if (_displayModule)
            _displayModule->operator->()->update(_clock->getDeltaTime(), *_eventManager,
                currentEntityManager);
    }
}

void Arcade::Core::Core::handleCoreEvents()
{
    auto eventGame = _eventManager->isEventTriggered(CHANGE_GAME);
    auto eventGraph = _eventManager->isEventTriggered(CHANGE_GRAPHIC);
    auto eventGameEnd = _eventManager->isEventTriggered(END_GAME);

    if (eventGame.first) {
        if (!eventGraph.second.has_value()) {
            loadGameModule();
        }
        for (auto &comp : *eventGame.second) {
            if (comp.has_value()) {
                std::string gameName = reinterpret_cast<Arcade::Game::Text &>(*comp.value()).text;
                loadGameModule(gameName);
                continue;
            }
            loadGameModule();
        }
    }
    if (eventGraph.first) {
        if (!eventGraph.second.has_value()) {
            loadDisplayModule();
        }
        for (auto &comp : *eventGraph.second) {
            if (comp.has_value()) {
                std::string libName = reinterpret_cast<Arcade::Game::Text &>(*comp.value()).text;
                loadDisplayModule(libName);
                continue;
            }
        }
    }
    if (eventGameEnd.first) {
        _currentGameModule = "";
        _gameModule.reset(nullptr);
    }
}

void Arcade::Core::Core::loadGameModule(const std::string &path)
{
    if (_currentGameModule == path)
        return;
    _currentGameModule = path;
    _gameModule = std::make_unique<GameHandler>(path);
}

void Arcade::Core::Core::loadGameModule()
{
    auto list = LibraryFinder::getLibraries();
    for (auto it = list.begin(); it != list.end();) {
        if (it->first != LibType::GAME) {
            it = list.erase(it);
        } else {
            ++it;
        }
    }
    auto it = list.begin();

    for (; it != list.end(); ++it) {
        if (it->second == _currentGameModule) {
            break;
        }
    }
    if (it == list.end()) {
        it = list.begin();
    }
    _gameModule = std::make_unique<GameHandler>(it->second);
    _currentGameModule = it->second;
}

void Arcade::Core::Core::loadDisplayModule(const std::string &path)
{
    if (_currentDisplayModule == path)
        return;
    _currentDisplayModule = path;
    _displayModule = std::make_unique<DisplayHandler>(path);
}

void Arcade::Core::Core::loadDisplayModule()
{
    auto list = LibraryFinder::getLibraries();
    for (auto it = list.begin(); it != list.end();) {
        if (it->first != LibType::GRAPH) {
            it = list.erase(it);
        } else {
            ++it;
        }
    }
    auto it = list.begin();

    for (; it != list.end(); ++it) {
        if (it->second == _currentDisplayModule) {
            break;
        }
    }
    if (it == list.end()) {
        it = list.begin();
    }
    _displayModule = std::make_unique<DisplayHandler>(it->second);
    _currentDisplayModule = it->second;
}
