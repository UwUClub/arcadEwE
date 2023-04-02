//
// Created by valegox on 30/03/23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "IEventManager.hpp"

namespace Arcade::Graph {
    class EventHandler
    {
        public:
        EventHandler() = default;
        ~EventHandler() = default;

        void run(Arcade::ECS::IEventManager &eventManager, sf::RenderWindow *window);
    };
}
