//
// Created by patatofour on 28/03/23.
//

#include "Component.hpp"

Arcade::ECS::Component::Component(CompType nType, const std::string &nId)
{
    type = nType;
    id = nId;
}
