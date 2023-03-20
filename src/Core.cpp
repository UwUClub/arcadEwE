//
// Created by patatofour on 20/03/23.
//

#include "Core.hpp"
#include "SystemManager.hpp"
#include "EventManager.hpp"

Arcade::Core::Core::Core()
{
    _systemManager = std::make_unique<ECS::SystemManager>();
    _eventManager = std::make_unique<ECS::EventManager>();
    _entityManager = std::make_unique<ECS::EntityManager>();
}

void Arcade::Core::Core::update()
{
    _systemManager->update(0, *_entityManager, *_eventManager);
}
