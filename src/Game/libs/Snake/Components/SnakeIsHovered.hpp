//
// Created by patatofour on 28/03/23.
//

#ifndef SNAKE_ISHOVERED_HPP
#define SNAKE_ISHOVERED_HPP

#include "IComponent.hpp"
#include "Component.hpp"

namespace Snake
{
    struct IsHovered final : public Arcade::ECS::IComponent {
        public:
        explicit IsHovered(const std::string &id);
        ~IsHovered() final = default;

        bool isHovered;
    };
} // namespace Snake

#endif // SNAKE_ISHOVERED_HPP
