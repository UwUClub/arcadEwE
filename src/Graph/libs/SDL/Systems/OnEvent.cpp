//
// Created by patatofour on 31/03/23.
//

#include <iostream>
#include "OnEvent.hpp"

namespace Arcade::Graph
{
    void OnEvent::run(Arcade::ECS::IEventManager &eventManager, SDL_Event &event)
    {
        if (event.type == SDL_WINDOWEVENT
            && windowEventMap.find(event.window.event) != windowEventMap.end()) {
            eventManager.addEvent(windowEventMap.at(event.window.event));
            return;
        }
        if (event.type == SDL_KEYDOWN && keyMap.find(event.key.keysym.sym) != keyMap.end()) {
            eventManager.addEvent(keyMap.at(event.key.keysym.sym));
            return;
        }
        if (event.type == SDL_MOUSEBUTTONDOWN
            && mouseButtonMap.find(event.button.button) != mouseButtonMap.end()) {
            eventManager.addEvent(mouseButtonMap.at(event.button.button));
            return;
        }
        if (baseEventMap.find(event.type) != baseEventMap.end()) {
            eventManager.addEvent(baseEventMap.at(event.type));
            return;
        }
    }
} // namespace Arcade::Graph
