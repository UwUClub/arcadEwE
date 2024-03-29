//
// Created by patatofour on 20/03/23.
//

#include <algorithm>
#include <iostream>
#include "EventManager.hpp"

Arcade::ECS::EventManager::EventManager() = default;

bool Arcade::ECS::EventManager::eventsIsEmpty() const
{
    return _events.empty();
}

void Arcade::ECS::EventManager::clearEvents()
{
    for (auto &event : _events) {
        if (event.second.has_value()) {
            event.second->clear();
        }
    }
    _events.clear();
}

std::pair<bool, std::optional<std::vector<std::optional<std::shared_ptr<Arcade::ECS::IComponent>>>>>
Arcade::ECS::EventManager::isEventTriggered(const std::string &event) const
{
    auto it = _events.find(event);

    if (it == _events.end())
        return { false, std::nullopt };
    return { true, it->second };
}

void Arcade::ECS::EventManager::addEvent(const std::string &event,
    std::optional<std::shared_ptr<IComponent>> component)
{
    auto it = _events.find(event);

    if (it == _events.end()) {
        _events.emplace(event, std::nullopt);
        it = _events.find(event);
    }

    if (component.has_value()) {
        if (!it->second.has_value())
            it->second = std::vector<std::optional<std::shared_ptr<IComponent>>>();
        it->second->emplace_back(component);
    }
}
