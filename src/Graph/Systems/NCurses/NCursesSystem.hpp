//
// Created by valegox on 22/03/23.
//

#pragma once

#include "ISystem.hpp"

namespace Arcade::Graph {
    class NCursesSystem : public Arcade::ECS::ISystem
    {
        public:
        NCursesSystem();
        ~NCursesSystem() override;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
    };
}
