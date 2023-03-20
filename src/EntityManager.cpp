//
// Created by patatofour on 20/03/23.
//

#include "EntityManager.hpp"
#include "Entity.hpp"

Arcade::ECS::EntityManager::EntityManager()
= default;

Arcade::ECS::IEntity &Arcade::ECS::EntityManager::createEntity()
{
    _entities.push_back(std::make_unique<Entity>(_entities.size()));
    return *_entities.back();
}

const std::vector<std::unique_ptr<Arcade::ECS::IEntity>> &Arcade::ECS::EntityManager::getEntities() const
{
    return _entities;
}

const std::vector<std::unique_ptr<Arcade::ECS::IEntity>> &Arcade::ECS::EntityManager::getEntitiesByComponentType(CompType type) const
{
    return _entities;
}
