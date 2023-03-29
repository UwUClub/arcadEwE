//
// Created by valegox on 22/03/23.
//

#pragma once

#include "AHandler.hpp"
#include "IEventManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph {
    class TextHandler : public Arcade::ECS::AHandler
    {
        public:
        TextHandler();
        ~TextHandler() = default;

        void run(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager) override;
    };
}
