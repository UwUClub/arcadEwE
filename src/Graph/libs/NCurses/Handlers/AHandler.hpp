//
// Created by valegox on 27/03/23.
//

#pragma once

#include "IHandler.hpp"
#include "IEventManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph {
    class AHandler : public IHandler
    {
        public:
        ~AHandler() = default;

        virtual void run(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager);
        void printContent(std::string content, int posX, int posY, Color foregroundColor, Color backgroundColor);
    };
}
