/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Movements
*/

#include "Movements.hpp"

namespace Snake {
    Movements::Movements(const std::string &id, const enum Movements::Direction direction) :
        Arcade::ECS::Component(ECS::CompType::MOVE, "id"),
        _direction(direction)
    {
    }

    Movements::~Movements()
    {
    }

    void Movements::setDirection(const enum Movements::Direction direction)
    {
        _direction = direction;
    }

    const enum Movements::Direction Movements::getDirection() const
    {
        return _direction;
    }

}
