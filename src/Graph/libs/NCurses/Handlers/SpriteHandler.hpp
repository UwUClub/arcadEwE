//
// Created by valegox on 22/03/23.
//

#pragma once

#include "AHandler.hpp"

namespace Arcade::Graph
{
    class SpriteHandler final : public AHandler
    {
        public:
        SpriteHandler();
        ~SpriteHandler() override = default;

        void run(float delta, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager) final;
    };
} // namespace Arcade::Graph
