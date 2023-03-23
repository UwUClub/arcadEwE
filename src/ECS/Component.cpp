//
// Created by patatofour on 20/03/23.
//

#include "Component.hpp"

#include <utility>

Arcade::ECS::Component::Component(CompType type, const std::string &id) : _type(type),
    _id(id)
{
}

Arcade::ECS::CompType Arcade::ECS::Component::getType() const
{
    return _type;
}

const std::string &Arcade::ECS::Component::getId() const
{
    return _id;
}
