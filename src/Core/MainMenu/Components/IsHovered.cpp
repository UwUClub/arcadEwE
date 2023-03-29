//
// Created by patatofour on 28/03/23.
//

#include "IsHovered.hpp"

Arcade::Game::IsHovered::IsHovered(const std::string &id)
{
    this->id = id;
    this->type = ECS::CompType::TEXT_HOVER;
    this->isHovered = false;
}
