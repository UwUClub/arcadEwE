//
// Created by valegox on 02/04/23.
//

#include <SFML/Graphics.hpp>
#include "Events.hpp"
#include "EventHandler.hpp"

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
