/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Sprite
*/

#include "SnakeSprite.hpp"

Snake::Sprite::Sprite(const std::string &id, const std::string &path, Arcade::Graph::TTYData ttyData,
    Arcade::Vector3f pos, Arcade::Graph::Rect rect, int currentRectIndex)
{
    this->id = id;
    this->type = Arcade::ECS::CompType::SPRITE;
    this->path = path;
    this->ttyData = ttyData;
    this->pos = pos;
    this->rect = rect;
    this->currentRectIndex = currentRectIndex;
}
