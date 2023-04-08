/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerSprite
*/

#ifndef SNAKE_SPRITE_HPP
#define SNAKE_SPRITE_HPP
#include "ISprite.hpp"
#include "Component.hpp"

namespace Nibbler
{
    struct Sprite final : public Arcade::Graph::ISprite {
        public:
        Sprite(const std::string &id, const std::string &path, Arcade::Graph::TTYData ttyData,
            Arcade::Vector3f pos, Arcade::Graph::Rect rect, int currentRectIndex);
        ~Sprite() final = default;
    };
} // namespace Nibbler

#endif // SNAKE_SPRITE_HPP
