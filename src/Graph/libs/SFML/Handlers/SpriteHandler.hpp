//
// Created by valegox on 30/03/23.
//

#pragma once

#include "IHandler.hpp"
#include "IEventManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph {
    class SpriteHandler : public IHandler
    {
        public:
        SpriteHandler() = default;
        ~SpriteHandler() = default;

        void run(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager);
    };
}
