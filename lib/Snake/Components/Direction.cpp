/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Direction
*/

#include "Direction.hpp"
#include "Snake.hpp"

namespace Snake {
    Direction::Direction(const std::string &id, const enum Direction::dir direction) :
        Arcade::ECS::Component(Arcade::ECS::CompType::DIRECTION, id),
        _direction(direction)
    {
    }

    void Direction::setDirection(const enum Direction::dir direction)
    {
        _direction = direction;
    }

    Direction::dir Direction::getDirection() const
    {
        return _direction;
    }

}
