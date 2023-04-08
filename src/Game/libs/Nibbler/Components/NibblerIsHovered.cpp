//
// Created by patatofour on 28/03/23.
//

#include "NibblerIsHovered.hpp"

Nibbler::IsHovered::IsHovered(const std::string &id)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::TEXT_HOVER;
    this->isHovered = false;
}
