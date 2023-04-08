//
// Created by patatofour on 28/03/23.
//

#ifndef NIBBLER_ISHOVERED_HPP
#define NIBBLER_ISHOVERED_HPP

#include "IComponent.hpp"
#include "Component.hpp"

namespace Nibbler
{
    struct IsHovered final : public Arcade::ECS::IComponent {
        public:
        explicit IsHovered(const std::string &id);
        ~IsHovered() final = default;

        bool isHovered;
    };
} // namespace Nibbler

#endif // NIBBLER_ISHOVERED_HPP
