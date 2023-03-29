/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Speed
*/

#include "Speed.hpp"

namespace Snake {
    Speed::Speed(const std::string &id, float speed) :
        Arcade::ECS::Component(Arcade::ECS::CompType::SPEED, id),
        _speed(speed)
    {
    }

    void Speed::setSpeed(float speed)
    {
        _speed = speed;
    }

    [[nodiscard]] float Speed::getSpeed() const
    {
        return _speed;
    }
}