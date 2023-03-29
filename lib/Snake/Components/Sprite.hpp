/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Sprite
*/

#ifndef SPRITE_HPP
    #define SPRITE_HPP
    #include "ISprite.hpp"

namespace Snake
{
    struct Sprite final : public Arcade::Graph::ISprite {
        public:
        Sprite(const std::string &id, const std::string &path, Arcade::Graph::TTYData ttyData,
            Arcade::Vector3f pos, Arcade::Graph::Rect rect, int currentRectIndex);
        ~Sprite() final = default;
    };
} // namespace Snake

#endif // SPRITE_HPP
