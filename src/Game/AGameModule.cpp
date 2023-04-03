//
// Created by patatofour on 28/03/23.
//

#include <iostream>
#include "AGameModule.hpp"

Arcade::Game::AGameModule::AGameModule()
    : _currentScene(0)
{
}

void Arcade::Game::AGameModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _scenes[_currentScene]->update(deltaTime, eventManager);
}

Arcade::ECS::IEntityManager &Arcade::Game::AGameModule::getCurrentEntityManager()
{
    return _scenes[_currentScene]->getEntityManager();
}

void Arcade::Game::AGameModule::changeScene(std::size_t sceneId)
{
    size_t i = _currentScene;

    if (sceneId == _currentScene)
        return;
    if (sceneId >= _scenes.size())
        throw AGameModuleException("Scene does not exist");
    _currentScene = sceneId;
    if (_scenes[sceneId]->init()) {
        _currentScene = sceneId;
        _scenes[i]->close();
    }
}
