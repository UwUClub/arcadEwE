//
// Created by patatofour on 28/03/23.
//

#include "Text.hpp"
#include "IComponent.hpp"

Arcade::Game::Text::Text(const std::string &id, const std::string &text, const std::string &font,
    Arcade::Graph::Color backColor, Arcade::Graph::Color textColor, Arcade::Vector3f pos)
{
    this->text = text;
    this->fontPath = font;
    this->textColor = textColor;
    this->backgroundColor = backColor;
    this->pos = pos;
    this->id = id;
    this->type = ECS::CompType::TEXT;
}
