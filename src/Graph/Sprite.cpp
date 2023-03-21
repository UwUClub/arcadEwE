//
// Created by patatofour on 21/03/23.
//

#include <utility>
#include "Sprite.hpp"

Arcade::Graph::Sprite::Sprite(std::string path, std::string id) :
    _path(std::move(path)),
    _id(std::move(id)),
    _pos({0, 0}),
    _size({0, 0}),
    _color({255, 255, 255, 255}),
    _rect({0, 0, 0, 0}),
    _scale(1.0f)
{
}

const std::string &Arcade::Graph::Sprite::getId() const
{
    return _id;
}

const std::string &Arcade::Graph::Sprite::getPath() const
{
    return _path;
}

const Arcade::Vector3f &Arcade::Graph::Sprite::getPos() const
{
    return _pos;
}

void Arcade::Graph::Sprite::setPos(Arcade::Vector3f pos)
{
    _pos = pos;
}

const Arcade::Vector3f &Arcade::Graph::Sprite::getSize() const
{
    return _size;
}

void Arcade::Graph::Sprite::setSize(Arcade::Vector3f size)
{
    _size = size;
}

const Arcade::Graph::Color &Arcade::Graph::Sprite::getColor() const
{
    return _color;
}

void Arcade::Graph::Sprite::setColor(Arcade::Graph::Color color)
{
    _color = color;
}

const Arcade::Graph::Rect &Arcade::Graph::Sprite::getRect() const
{
    return _rect;
}

void Arcade::Graph::Sprite::setRect(Arcade::Graph::Rect rect)
{
    _rect = rect;
}

const float &Arcade::Graph::Sprite::getScale() const
{
    return _scale;
}

void Arcade::Graph::Sprite::setScale(float scale)
{
    _scale = scale;
}

const Arcade::Graph::TTYData &Arcade::Graph::Sprite::getNcurseData() const
{
    return _ncurseData;
}
