//
// Created by valegox on 22/03/23.
//

#pragma once

#include "AHandler.hpp"
#include "IEventManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph
{
    class TextHandler : public AHandler
    {
        public:
        TextHandler();
        ~TextHandler() = default;

        void run(double delta, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager);
    };
} // namespace Arcade::Graph
