//
// Created by valegox on 29/03/23.
//

#include "AScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

namespace Arcade::Game
{

    AScene::AScene()
        : _entityManager(std::make_unique<Arcade::ECS::EntityManager>())
        , _systemManager(std::make_unique<Arcade::ECS::SystemManager>())
    {
    }

    void AScene::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
    {
        _systemManager->update(deltaTime, eventManager, *_entityManager);
    }

    Arcade::ECS::IEntityManager &Arcade::Game::AScene::getEntityManager()
    {
        return *_entityManager;
    }

    void Arcade::Game::AScene::close()
    {
        _entityManager->removeAllEntities();
        _entityManager.reset(new Arcade::ECS::EntityManager());
        _systemManager.reset(new Arcade::ECS::SystemManager());
    }
} // namespace Arcade::Game
