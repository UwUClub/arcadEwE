//
// Created by valegox on 04/04/23.
//

#ifndef ARCADE_SPRITE_HPP
#define ARCADE_SPRITE_HPP

#include "GraphStruct.hpp"
#include "IComponent.hpp"
#include "ISprite.hpp"
#include "Component.hpp"

namespace Arcade::Game
{
    struct Sprite final : public Arcade::Graph::ISprite {
        public:
        Sprite(const std::string &id, const std::string &path,
            const Arcade::Graph::TTYData &ttyData, const Arcade::Vector3f pos,
            Arcade::Graph::Rect rect, int currentRectIndex);
        ~Sprite() final = default;
    };
} // namespace Arcade::Game

#endif // ARCADE_SPRITE_HPP
