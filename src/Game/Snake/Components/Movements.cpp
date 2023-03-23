/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Movements
*/

#include "Movements.hpp"

namespace Snake {
    Movements::Movements() : Arcade::ECS::Component(Displace, "Movements")
    {
    }

    Movements::~Movements()
    {
    }

    void Movements::setDirection(Direction direction)
    {
        _direction = direction;
    }

    enum Direction Movements::getDirection() const
    {
        return _direction;
    }

}
