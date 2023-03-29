//
// Created by valegox on 27/03/23.
//

#pragma once

#include "IEventManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph {
    class IHandler
    {
        public:
        ~IHandler() = default;

        virtual void run(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager);
    };
}
