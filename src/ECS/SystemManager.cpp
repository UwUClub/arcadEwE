//
// Created by patatofour on 20/03/23.
//

#include "SystemManager.hpp"

void Arcade::ECS::SystemManager::addSystem(const std::string &name, Arcade::ECS::ISystem *system)
{
    if (_systems.find(name) != _systems.end())
        throw std::runtime_error("System already exists");
    _systems[name] = std::unique_ptr<ISystem>(system);
}

void Arcade::ECS::SystemManager::removeSystem(const std::string &name)
{
    if (_systems.find(name) == _systems.end())
        throw std::runtime_error("System does not exist");
    _systems.erase(name);
}

void Arcade::ECS::SystemManager::update(std::size_t deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    for (auto &system : _systems) {
        system.second->run(deltaTime, eventManager, displayModule, gameModule);
    }
}
