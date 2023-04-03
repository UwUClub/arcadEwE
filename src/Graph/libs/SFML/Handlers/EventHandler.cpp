//
// Created by valegox on 02/04/23.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Events.hpp"
#include "EventHandler.hpp"
#include "ArcadeStruct.hpp"

namespace Arcade::Graph
{
    void EventHandler::run(Arcade::ECS::IEventManager &eventManager, sf::RenderWindow *window)
    {
        sf::Event event;
        window->pollEvent(event);
        if (event.type == sf::Event::Closed) {
            eventManager.addEvent(QUIT);
        }
        if (event.type == sf::Event::KeyPressed) {
            if (keyMap.find(event.key.code) != keyMap.end()) {
                eventManager.addEvent(keyMap.at(event.key.code));
            }
        }
    }
} // namespace Arcade::Graph
