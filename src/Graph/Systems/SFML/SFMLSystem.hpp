//
// Created by valegox on 23/03/23.
//

#pragma once

#include "ISystem.hpp"
#include <SFML/Graphics.hpp>

namespace Arcade::Graph {
    class SFMLSystem : public Arcade::ECS::ISystem
    {
        public:
        SFMLSystem();
        ~SFMLSystem() override;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
        
        protected:
        sf::RenderWindow _window;
    };
}
