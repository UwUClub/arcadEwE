/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerScene
*/

#include "NibblerScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"

namespace Nibbler
{
    NibblerScene::NibblerScene()
        : _entityManager(std::make_unique<Arcade::ECS::EntityManager>())
        , _systemManager(std::make_unique<Arcade::ECS::SystemManager>())
    {
    }

    void NibblerScene::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
    {
        _systemManager->update(deltaTime, eventManager, *_entityManager);
    }

    Arcade::ECS::IEntityManager &NibblerScene::getEntityManager()
    {
        return *_entityManager;
    }

    void NibblerScene::close()
    {
        _entityManager.reset(nullptr);
        _systemManager.reset(nullptr);
    }
} // namespace Nibbler
