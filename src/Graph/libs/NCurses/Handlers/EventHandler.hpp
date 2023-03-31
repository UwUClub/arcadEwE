//
// Created by valegox on 22/03/23.
//

#pragma once

#include "AHandler.hpp"

namespace Arcade::Graph {
    class EventHandler : public AHandler
    {
        public:
        EventHandler();
        ~EventHandler() = default;

        void run(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager);
    };
}
