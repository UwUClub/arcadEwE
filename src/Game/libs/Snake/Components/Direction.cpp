/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Direction
*/

#include "Direction.hpp"

namespace Snake {
    Direction::Direction(const std::string &id, const enum Direction::dir direction) :
        Arcade::ECS::Component(Arcade::ECS::CompType::DIRECTION, id),
        _direction(direction), _nextDirection(direction)
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

    void Direction::setNextDirection(const enum Direction::dir direction)
    {
        _nextDirection = direction;
    }

    Direction::dir Direction::getNextDirection() const
    {
        return _nextDirection;
    }
}
