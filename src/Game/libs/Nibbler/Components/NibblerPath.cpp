/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerNibblerPath
*/

#include "NibblerPath.hpp"

namespace Nibbler
{
    NibblerPath::NibblerPath(const std::string &id) : Component( Arcade::ECS::CompType::SPEED, id)
    {
    }

    void NibblerPath::addPoint(enum Direction::dir direction, Arcade::Vector3f position)
    {
        _path.push({direction, position});
    }

    void NibblerPath::popPoint()
    {
        _path.pop();
    }

    std::pair<enum Direction::dir, Arcade::Vector3f> NibblerPath::getPoint() const
    {
        if (!_path.empty()) {
            return _path.front();
        }
        return {Direction::dir::UP, {-1, -1, -1}};
    }
}