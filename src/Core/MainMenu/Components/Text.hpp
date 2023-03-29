//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "IText.hpp"

namespace Arcade::Game
{
    struct Text final : public Arcade::Graph::IText {
        public:
        Text(const std::string &id, const std::string &text, const std::string &font,
            Arcade::Graph::Color backColor, Arcade::Graph::Color textColor, Arcade::Vector3f pos);
        ~Text() final = default;
    };
} // namespace Arcade::Game

#endif // ARCADE_TEXT_HPP
