//
// Created by patatofour on 21/03/23.
//

#include <utility>
#include "Sprite.hpp"

Arcade::Graph::Sprite::Sprite(const std::string &path, const std::string &id) :
    _path(path),
    _id(id),
    _cliData({}),
    _pos({ 0, 0, 0 }),
    _size({ 0, 0, 0 }),
    _color({ 255, 255, 255, 255 }),
    _rect({ 0, 0, 0, 0 }),
    _scale(1)
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

void Arcade::Graph::Sprite::setColor(const Arcade::Graph::Color &color)
{
    _color = color;
}

const Arcade::Graph::Rect &Arcade::Graph::Sprite::getRect() const
{
    return _rect;
}

void Arcade::Graph::Sprite::setRect(const Arcade::Graph::Rect &rect)
{
    _rect = rect;
}

float Arcade::Graph::Sprite::getScale() const
{
    return _scale;
}

void Arcade::Graph::Sprite::setScale(float scale)
{
    _scale = scale;
}

const Arcade::Graph::TTYData &Arcade::Graph::Sprite::getTTYData() const
{
    return _cliData;
}

void Arcade::Graph::Sprite::setTTYData(const Arcade::Graph::TTYData &data)
{
    _cliData = data;
}

void Arcade::Graph::Sprite::setPath(const std::string &path)
{
    _path = path;
}
