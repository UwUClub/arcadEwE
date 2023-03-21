//
// Created by patatofour on 20/03/23.
//

#include "EntityManager.hpp"
#include "Entity.hpp"

Arcade::ECS::EntityManager::EntityManager()
= default;

Arcade::ECS::IEntity &Arcade::ECS::EntityManager::createEntity(const std::string &name)
{
    std::shared_ptr<Arcade::ECS::IEntity> entity = nullptr;

    entity = std::shared_ptr<Arcade::ECS::IEntity>(new Arcade::ECS::Entity(name));
    _entities.push_back(entity);
    return *_entities.back();
}

const std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &Arcade::ECS::EntityManager::getEntities() const
{
    return _entities;
}

std::unique_ptr<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>>
Arcade::ECS::EntityManager::getEntitiesByComponentType(Arcade::ECS::CompType comp) const
{
    auto entities = std::make_unique<std::vector<std::shared_ptr<Arcade::ECS::IEntity>>>();

    for (const auto& entity : _entities) {
        if (entity->getComponents().find(comp) != entity->getComponents().end())
            entities->push_back(entity);
    }
    return entities;
}

void Arcade::ECS::EntityManager::removeEntity(std::string id)
{
    for (auto it = _entities.begin(); it != _entities.end(); ++it) {
        if ((*it)->getId() == id) {
            _entities.erase(it);
            return;
        }
    }
}

void Arcade::ECS::EntityManager::removeAllEntities()
{
    _entities.clear();
}
