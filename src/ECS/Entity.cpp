//
// Created by patatofour on 20/03/23.
//

#include <utility>
#include "Entity.hpp"

Arcade::ECS::Entity::Entity(const std::string &id) : _id(id)
{
}

std::string Arcade::ECS::Entity::getId() const
{
    return _id;
}

void Arcade::ECS::Entity::addComponent(std::shared_ptr<Arcade::ECS::IComponent> component)
{
    _components[component->getType()].push_back(std::move(component));
}

const std::map<Arcade::ECS::CompType, std::vector<std::shared_ptr<Arcade::ECS::IComponent>>> &
Arcade::ECS::Entity::getComponents()
{
    return _components;
}

const std::vector<std::shared_ptr<Arcade::ECS::IComponent>> &Arcade::ECS::Entity::getComponents(Arcade::ECS::CompType type)
{
    return _components[type];
}

void Arcade::ECS::Entity::removeComponent(std::string id)
{
    for (auto &component : _components) {
        for (auto it = component.second.begin(); it != component.second.end(); ++it) {
            if ((*it)->getId() == id) {
                component.second.erase(it);
                return;
            }
        }
    }
}

void Arcade::ECS::Entity::removeComponents(Arcade::ECS::CompType type)
{
    _components[type].clear();
}
