//
// Created by valegox on 02/04/23.
//

#include <SFML/Graphics.hpp>
#include "Events.hpp"
#include "EventHandler.hpp"

namespace Arcade::Graph {

    void EventHandler::run(Arcade::ECS::IEventManager &eventManager, sf::RenderWindow *window)
    {
        sf::Event _event;
        window->pollEvent(_event);
        if (_event.type == sf::Event::Closed) {
            eventManager.addEvent(QUIT);
        }
    }
}
