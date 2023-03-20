//
// Created by patatofour on 20/03/23.
//

#include "AComponent.hpp"

Arcade::ECS::AComponent::AComponent(CompType type) : _type(type)
{
}

Arcade::ECS::CompType Arcade::ECS::AComponent::getType() const
{
    return _type;
}
