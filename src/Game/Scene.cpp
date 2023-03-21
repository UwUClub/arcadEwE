//
// Created by patatofour on 21/03/23.
//

#include "Scene.hpp"

Arcade::Game::Scene::Scene(std::unique_ptr<Arcade::ECS::IEntityManager> entityManager,
    std::unique_ptr<Arcade::ECS::ISystemManager> systemManager) :
    _entityManager(std::move(entityManager)),
    _systemManager(std::move(systemManager))
{
}

Arcade::ECS::IEntityManager &Arcade::Game::Scene::getEntityManager()
{
    return *_entityManager;
}

Arcade::ECS::ISystemManager &Arcade::Game::Scene::getSystemManager()
{
    return *_systemManager;
}
