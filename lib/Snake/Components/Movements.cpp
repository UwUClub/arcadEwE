/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Movements
*/

#include "Movements.hpp"
#include "Snake.hpp"

namespace Snake {
    Movements::Movements(const std::string &id, const enum Movements::Direction direction) :
        Arcade::ECS::Component(Arcade::ECS::CompType::MOVEMENTS, id),
        _direction(direction)
    {
    }

    void Movements::setDirection(const enum Movements::Direction direction)
    {
        _direction = direction;
    }

    Movements::Direction Movements::getDirection() const
    {
        return _direction;
    }

}
