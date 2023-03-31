/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Position
*/

#include "Position.hpp"

namespace Snake {
    Position::Position(const std::string &id, Arcade::Vector3f pos) :
        Arcade::ECS::Component(Arcade::ECS::CompType::POSITION, id),
        pos(pos)
    {
    }
}
