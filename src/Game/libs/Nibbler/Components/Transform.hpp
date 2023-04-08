/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_
#include "Component.hpp"
#include "ArcadeStruct.hpp"
#include "Component.hpp"

namespace Nibbler
{
    struct Transform final : public Arcade::ECS::Component {
        public:
        Transform(const std::string &id);
        Transform(const std::string &id, Arcade::Vector3f position);
        Transform(const std::string &id, Arcade::Vector3f position, Arcade::Vector3f rotation);
        ~Transform() final = default;

        void Translate(Arcade::Vector3f position);
        void Rotate(Arcade::Vector3f rotate);

        Arcade::Vector3f getPosition() const;
        Arcade::Vector3f getRotation() const;

        void setPosition(Arcade::Vector3f position);
        void setRotation(Arcade::Vector3f rotation);

        public:
        Arcade::Vector3f position;
        Arcade::Vector3f rotation;
    };
} // namespace Nibbler

#endif /* !TRANSFORM_HPP_ */