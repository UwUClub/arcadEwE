//
// Created by valegox on 24/04/23.
//

#include "Music.hpp"
#include "IComponent.hpp"

Arcade::Game::Music::Music(const std::string &id, const std::string &path, bool loop, bool play)
{
    this->id = id;
    this->path = path;
    this->loop = loop;
    this->play = play;
    this->type = ECS::CompType::MUSIC;
}
