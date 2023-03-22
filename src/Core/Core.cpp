//
// Created by patatofour on 20/03/23.
//

#include "Core.hpp"
#include "LibraryHandler.hpp"
#include "EventManager.hpp"
#include "DisplayModule.hpp"
#include "GameModule.hpp"
#include "Component.hpp"

Arcade::Core::Core::Core()
{
    auto libs = LibraryHandler::getLibraries();

    _displayModule = std::make_unique<DisplayModule>(libs);
    _gameModule = std::make_unique<GameModule>(libs);
    _eventManager = std::make_unique<ECS::EventManager>();
}

void Arcade::Core::Core::run()
{
    while (_eventManager->isEventTriggered("QUIT").first) {
        auto &gameSys = _gameModule->getSceneManager()
                            .getCurrentScene()
                            ->getSystemManager();
        auto &displaySys = _displayModule->getSystemManager();

        gameSys.update(0, *_eventManager, *_displayModule, *_gameModule);
        displaySys.update(0, *_eventManager, *_displayModule, *_gameModule);
        handleCoreEvents();
    }
}

void Arcade::Core::Core::handleCoreEvents()
{
    auto event = _eventManager->isEventTriggered("CHANGE_GAME");

    if (event.first) {
        for (auto &comp : *event.second) {
            if (comp.has_value()) {
                std::string gameName = comp.value()->getId();
                _gameModule->changeGame(gameName);
                continue;
            }
            _gameModule->changeGame();
        }
    }
    event = _eventManager->isEventTriggered("CHANGE_LIB");
    if (event.first) {
        for (auto &comp : *event.second) {
            if (comp.has_value()) {
                std::string libName = comp.value()->getId();
                _displayModule->changeGraphicLib(libName);
                continue;
            }
            _displayModule->changeGraphicLib();
        }
    }
}
