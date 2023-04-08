//
// Created by patatofour on 20/03/23.
//

#include <memory>
#include <iostream>
#include "Core.hpp"
#include "EventManager.hpp"
#include "Component.hpp"
#include "Events.hpp"
#include "Text.hpp"

Arcade::Core::Core::Core(const std::string &pathDisplay)
    : _clock(std::make_unique<Arcade::Core::Clock>())
{
    auto libs = LibraryFinder::getLibraries();

    _currentGameModule = MENU_PATH;
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

    try {
        _gameModule = std::make_unique<GameHandler>(_currentGameModule);
        _displayModule = std::make_unique<DisplayHandler>(_currentDisplayModule);
        _eventManager = std::make_unique<ECS::EventManager>();
    } catch (const DisplayHandler::LibraryHandlerException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

void Arcade::Core::Core::update()
{
    while (!_eventManager->isEventTriggered(QUIT).first) {
        _gameModule->operator->()->update(_clock->getDeltaTime(), *_eventManager);
        handleCoreEvents();
        auto &currentEntityManager = _gameModule->operator->()->getCurrentEntityManager();

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
    auto eventTab = _eventManager->isEventTriggered(KEY_TAB_PRESSED);
    auto eventSpace = _eventManager->isEventTriggered(KEY_SPACE_PRESSED);

    if (eventGame.first) {
        if (!eventGame.second.has_value()) {
            loadGameModule();
        }
        for (auto &comp : *eventGame.second) {
            if (comp.has_value()) {
                std::string gameName = reinterpret_cast<Arcade::Game::Text &>(*comp.value()).text;
                loadGameModule(gameName);
                return;
            }
        }
    }
    if (eventGraph.first) {
        if (!eventGraph.second.has_value()) {
            loadDisplayModule();
        }
        for (auto &comp : *eventGraph.second) {
            if (comp.has_value()) {
                std::string libName = reinterpret_cast<Arcade::Game::Text &>(*comp.value()).text;
                libName = "./lib/arcade_" + libName + ".so";
                loadDisplayModule(libName);
                return;
            }
        }
    }
    if (eventGameEnd.first) {
        loadGameModule(MENU_PATH);
    }
    if (eventTab.first) {
        loadGameModule();
    }
    if (eventSpace.first) {
        loadDisplayModule();
    }
}

void Arcade::Core::Core::loadGameModule(const std::string &path)
{
    if (_currentGameModule == path)
        return;
    try {
        _currentGameModule = path;
        _gameModule = std::make_unique<GameHandler>(path);
    } catch (const DisplayHandler::LibraryHandlerException &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
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
    ++it;
    if (it == list.end()) {
        it = list.begin();
    }
    loadGameModule(it->second);
}

void Arcade::Core::Core::loadDisplayModule(const std::string &path)
{
    if (_currentDisplayModule == path)
        return;
    try {
        std::cout << "Loading " << path << std::endl;
        _displayModule.reset(nullptr);
        _displayModule = std::make_unique<DisplayHandler>(path);
        _currentDisplayModule = path;
    } catch (const DisplayHandler::LibraryHandlerException &e) {
        std::cout << "FAIL" << std::endl;
        std::cerr << e.what() << std::endl;
        exit(84);
    }
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
        if (it->second == _currentDisplayModule || it->second == "./" + _currentDisplayModule) {
            break;
        }
    }

    ++it;
    if (it == list.end()) {
        it = list.begin();
    }
    loadDisplayModule(it->second);
}
