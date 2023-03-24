//
// Created by patatofour on 21/03/23.
//

#include "Text.hpp"

Arcade::Graph::Text::Text(const std::string &id, const std::string &text,
    const Arcade::Graph::Color &backgroundColor, const Arcade::Graph::Color &foregroundColor,
    const Arcade::Vector2f &pos, const std::string &fontPath, float policeSize)
    : _id(id)
    , _fontPath(fontPath)
    , _text(text)
    , _backgroundColor(backgroundColor)
    , _foregroundColor(foregroundColor)
    , _fontSize(policeSize)
    , _pos(pos)
{
}

const std::string &Arcade::Graph::Text::getId() const { return _id; }

Arcade::ECS::CompType Arcade::Graph::Text::getType() const { return _type; }

const std::string &Arcade::Graph::Text::getFontPath() const { return _fontPath; }

void Arcade::Graph::Text::setFontPath(const std::string &fontPath) { _fontPath = fontPath; }

const std::string &Arcade::Graph::Text::getText() const { return _text; }

void Arcade::Graph::Text::setText(const std::string &text) { _text = text; }

const Arcade::Graph::Color &Arcade::Graph::Text::getBackgroundColor() const
{
    return _backgroundColor;
}

void Arcade::Graph::Text::setBackgroundColor(const Arcade::Graph::Color &backgroundColor)
{
    _backgroundColor = backgroundColor;
}

const Arcade::Graph::Color &Arcade::Graph::Text::getForegroundColor() const
{
    return _foregroundColor;
}

void Arcade::Graph::Text::setForegroundColor(const Arcade::Graph::Color &foregroundColor)
{
    _foregroundColor = foregroundColor;
}

float Arcade::Graph::Text::getPoliceSize() const { return _fontSize; }

void Arcade::Graph::Text::setPoliceSize(float policeSize) { _fontSize = policeSize; }

const Arcade::Vector2f &Arcade::Graph::Text::getPos() const { return _pos; }

void Arcade::Graph::Text::setPos(const Arcade::Vector2f &pos) { _pos = pos; }
