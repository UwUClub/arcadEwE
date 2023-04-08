/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Text
*/

#ifndef NIBBLER_TEXT_HPP
#define NIBBLER_TEXT_HPP
#include "IText.hpp"
#include "Component.hpp"

namespace Nibbler
{
    struct Text final : public Arcade::Graph::IText {
        public:
        Text(const std::string &id, const std::string &text, const std::string &font,
            Arcade::Graph::Color backColor, Arcade::Graph::Color textColor, Arcade::Vector3f pos);
        ~Text() final = default;
    };
} // namespace Nibbler

#endif // NIBBLER_TEXT_HPP
