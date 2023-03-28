//
// Created by patatofour on 28/03/23.
//

#include "MainMenuScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

Arcade::Game::MainMenuScene::MainMenuScene()
    : _entityManager(std::make_unique<Arcade::ECS::EntityManager>())
    , _systemManager(std::make_unique<Arcade::ECS::SystemManager>())
{
}

void Arcade::Game::MainMenuScene::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _systemManager->update(deltaTime, eventManager, *_entityManager);
}

Arcade::ECS::IEntityManager &Arcade::Game::MainMenuScene::getEntityManager()
{
    return *_entityManager;
}
