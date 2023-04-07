//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_ISHOVERED_HPP
#define ARCADE_ISHOVERED_HPP

#include "IComponent.hpp"
#include "Component.hpp"

namespace Arcade::Game
{
    struct IsHovered final : public Arcade::ECS::IComponent {
        public:
        explicit IsHovered(const std::string &id);
        ~IsHovered() final = default;

        bool isHovered;
    };
} // namespace Arcade::Game

#endif // ARCADE_ISHOVERED_HPP
