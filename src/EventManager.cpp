//
// Created by patatofour on 20/03/23.
//

#include <algorithm>
#include "EventManager.hpp"

Arcade::ECS::EventManager::EventManager()
= default;

bool Arcade::ECS::EventManager::eventsIsEmpty() const
{
    return _events.empty();
}

bool Arcade::ECS::EventManager::isEventInQueue(const std::string &eventName) const
{
    return std::find(_events.begin(), _events.end(), eventName) != _events.end();
}

void Arcade::ECS::EventManager::addEvent(const std::string &eventName)
{
    _events.push_back(eventName);
}

const std::string &Arcade::ECS::EventManager::popEvent()
{
    const std::string &event = _events.front();

    _events.erase(_events.begin());
    return event;
}

void Arcade::ECS::EventManager::clearEvents()
{
    _events.clear();
}

const Arcade::Vector2f &Arcade::ECS::EventManager::getMousePosition() const
{
    return _mousePosition;
}

void Arcade::ECS::EventManager::setMousePosition(const Arcade::Vector2f &mousePosition)
{
    _mousePosition = mousePosition;
}
