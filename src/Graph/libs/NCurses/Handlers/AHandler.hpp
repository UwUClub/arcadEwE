//
// Created by valegox on 27/03/23.
//

#pragma once

#include "IHandler.hpp"
#include "IEventManager.hpp"
#include "IEntityManager.hpp"
#include "GraphStruct.hpp"

namespace Arcade::Graph
{
    class AHandler : public IHandler
    {
        public:
        AHandler();
        ~AHandler() = default;

        virtual void run(double delta, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager)
            = 0;
        void printContent(std::string content, int posX, int posY, Color foregroundColor,
            Color backgroundColor);
        void resetColors();

        protected:
        int _nbColorPairs;
        int _nbColors;
    };
} // namespace Arcade::Graph
