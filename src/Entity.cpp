//
// Created by patatofour on 20/03/23.
//

#include "Entity.hpp"

Arcade::ECS::Entity::Entity(std::size_t id) : _id(id)
{
}

std::size_t Arcade::ECS::Entity::getId() const
{
    return _id;
}

const std::vector<std::unique_ptr<Arcade::ECS::IComponent>> &Arcade::ECS::Entity::getComponents()
{
    return _components;
}

const std::vector<std::unique_ptr<Arcade::ECS::IComponent>> &Arcade::ECS::Entity::getComponents(CompType type)
{
    return _components;
}

void Arcade::ECS::Entity::addComponent(std::unique_ptr<Arcade::ECS::IComponent> component)
{
    _components.push_back(std::move(component));
}
