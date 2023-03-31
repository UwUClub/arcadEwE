/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Transform
*/

#include "Transform.hpp"

namespace Snake {
    Transform::Transform(const std::string &id) :
        Arcade::ECS::Component(Arcade::ECS::CompType::TRANSFORM, id),
        position({0, 0, 0}),
        rotation({0, 0, 0})
    {
    }

    Transform::Transform(const std::string &id, Arcade::Vector3f position) :
        Arcade::ECS::Component(Arcade::ECS::CompType::TRANSFORM, id),
        position(position),
        rotation({0, 0, 0})
    {
    }

    Transform::Transform(const std::string &id, Arcade::Vector3f position, Arcade::Vector3f rotation) :
        Arcade::ECS::Component(Arcade::ECS::CompType::TRANSFORM, id),
        position(position),
        rotation(rotation)
    {
    }

    void Transform::Translate(Arcade::Vector3f position)
    {
        this->position.x += position.x;
        this->position.y += position.y;
        this->position.z += position.z;
    }

    void Transform::Rotate(Arcade::Vector3f rotate)
    {
        this->rotation.x += rotate.x;
        this->rotation.y += rotate.y;
        this->rotation.z += rotate.z;
    }

    Arcade::Vector3f Transform::getPosition() const
    {
        return position;
    }

    Arcade::Vector3f Transform::getRotation() const
    {
        return rotation;
    }

    void Transform::setPosition(Arcade::Vector3f position)
    {
        this->position = position;
    }

    void Transform::setRotation(Arcade::Vector3f rotation)
    {
        this->rotation = rotation;
    }
}
