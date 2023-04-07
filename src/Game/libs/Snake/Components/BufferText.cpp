//
// Created by patatofour on 07/04/23.
//

#include "BufferText.hpp"

Snake::BufferText::BufferText(const std::string& id)
    : Arcade::ECS::Component(Arcade::ECS::CompType::BUFFERTEXT, id)
    , isBuffer(true)
{
}
