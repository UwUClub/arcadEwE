//
// Created by patatofour on 28/03/23.
//

#include "SystemManager.hpp"

void Arcade::ECS::SystemManager::removeSystem(const std::string &name)
{
    if (_systems.find(name) == _systems.end())
        throw SystemManagerException("System does not exist");
    _systems.erase(name);
}

void Arcade::ECS::SystemManager::update(double deltaTime, Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    if (_systems.empty())
        return;
    for (auto &system : _systems) {
        system.second->run(deltaTime, eventManager, currentEntityManager);
    }
}

void Arcade::ECS::SystemManager::addSystem(const std::string &name,
    std::unique_ptr<Arcade::ECS::ISystem> system)
{
    if (_systems.find(name) != _systems.end())
        throw SystemManagerException("System already exists");
    _systems[name] = std::move(system);
}
