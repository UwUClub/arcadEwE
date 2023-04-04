//
// Created by valegox on 24/04/23.
//

#include "Sprite.hpp"
#include "IComponent.hpp"

Arcade::Game::Sprite::Sprite(const std::string &id, const std::string &path, const Arcade::Graph::TTYData &ttyData,
    const Arcade::Vector3f pos, Arcade::Graph::Rect rect, int currentRectIndex)
{
    this->id = id;
    this->path = path;
    this->ttyData = ttyData;
    this->pos = pos;
    this->rect = rect;
    this->currentRectIndex = currentRectIndex;
    this->type = ECS::CompType::SPRITE;
}
