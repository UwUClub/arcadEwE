/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Text
*/

#include "NibblerText.hpp"

Nibbler::Text::Text(const std::string &id, const std::string &text, const std::string &font,
    Arcade::Graph::Color backColor, Arcade::Graph::Color textColor, Arcade::Vector3f pos)
{
    this->text = text;
    this->fontPath = font;
    this->textColor = textColor;
    this->backgroundColor = backColor;
    this->pos = pos;
    this->id = id;
    this->type = Arcade::ECS::CompType::TEXT;
}
