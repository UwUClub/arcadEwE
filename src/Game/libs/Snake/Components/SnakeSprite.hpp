/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeSprite
*/

#ifndef SNAKE_SPRITE_HPP
#define SNAKE_SPRITE_HPP
#include "ISprite.hpp"
#include "Component.hpp"

namespace Snake
{
    struct Sprite final : public Arcade::Graph::ISprite {
        public:
        Sprite(const std::string &id, const std::string &path, Arcade::Graph::TTYData ttyData,
            Arcade::Vector3f pos, Arcade::Graph::Rect rect, int currentRectIndex);
        ~Sprite() final = default;
    };
} // namespace Snake

#endif // SNAKE_SPRITE_HPP
