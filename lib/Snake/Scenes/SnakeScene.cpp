/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeScene
*/

#include "SnakeScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

namespace Snake {
    SnakeScene::SnakeScene()
    : _entityManager(std::make_unique<Arcade::ECS::EntityManager>())
    , _systemManager(std::make_unique<Arcade::ECS::SystemManager>())
    {
    }

    void SnakeScene::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
    {
        _systemManager->update(deltaTime, eventManager, *_entityManager);
    }

    Arcade::ECS::IEntityManager &SnakeScene::getEntityManager()
    {
        return *_entityManager;
    }
}
