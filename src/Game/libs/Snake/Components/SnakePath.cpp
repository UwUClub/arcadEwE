/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeSnakePath
*/

#include "SnakePath.hpp"

namespace Snake
{
    SnakePath::SnakePath(const std::string &id) : Component( Arcade::ECS::CompType::SPEED, id)
    {
    }

    void SnakePath::addPoint(enum Direction::dir direction, Arcade::Vector3f position)
    {
        _path.push({direction, position});
    }

    void SnakePath::popPoint()
    {
        _path.pop();
    }

    std::pair<enum Direction::dir, Arcade::Vector3f> SnakePath::getPoint() const
    {
        if (!_path.empty()) {
            return _path.front();
        }
        return {Direction::dir::UP, {-1, -1, -1}};
    }
}