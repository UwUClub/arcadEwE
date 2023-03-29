//
// Created by patatofour on 20/03/23.
//

#include <utility>
#include "Entity.hpp"

Arcade::ECS::Entity::Entity(const std::string &id)
    : _id(id)
{
}

std::string Arcade::ECS::Entity::getId() const { return _id; }

void Arcade::ECS::Entity::addComponent(std::shared_ptr<Arcade::ECS::IComponent> component)
{
    _components[component->type].push_back(std::move(component));
}

const std::map<Arcade::ECS::CompType, std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> &
Arcade::ECS::Entity::getComponents() const
{
    return _components;
}

const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &Arcade::ECS::Entity::getComponents(
    Arcade::ECS::CompType type) const
{
    return _components.at(type);
}

void Arcade::ECS::Entity::removeComponent(const std::string &id)
{
    for (auto &component : _components) {
        for (auto it = component.second.begin(); it != component.second.end(); ++it) {
            if ((*it)->id == id) {
                component.second.erase(it);
                return;
            }
        }
    }
}

void Arcade::ECS::Entity::removeComponent(Arcade::ECS::CompType type) { _components[type].clear(); }

Arcade::ECS::IComponent &Arcade::ECS::Entity::getComponents(const std::string &id)
{
    for (auto &component : _components) {
        for (auto &it : component.second) {
            if (it->id == id) {
                return *it;
            }
        }
    }
    throw EntityException("Component not found");
}
