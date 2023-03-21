//
// Created by patatofour on 20/03/23.
//

#include "AComponent.hpp"

#include <utility>

Arcade::ECS::AComponent::AComponent(CompType type, std::string id) : _type(type),
    _id(std::move(id))
{
}

Arcade::ECS::CompType Arcade::ECS::AComponent::getType() const
{
    return _type;
}

const std::string &Arcade::ECS::AComponent::getId() const
{
    return _id;
}
