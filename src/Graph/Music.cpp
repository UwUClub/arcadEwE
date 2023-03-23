//
// Created by patatofour on 21/03/23.
//

#include "Music.hpp"

#include <utility>

Arcade::Graph::Music::Music(const std::string &path, const std::string &id) :
    _path(path),
    _id(id),
    _loop(false),
    _isPlaying(false),
    _volume(100)
{
}

const std::string &Arcade::Graph::Music::getPath() const
{
    return _path;
}

Arcade::ECS::CompType Arcade::Graph::Music::getType() const
{
    return _type;
}

const std::string &Arcade::Graph::Music::getId() const
{
    return _id;
}

bool Arcade::Graph::Music::getLoop() const
{
    return _loop;
}

void Arcade::Graph::Music::setLoop(bool loop)
{
    _loop = loop;
}

bool Arcade::Graph::Music::getIsPlaying() const
{
    return _isPlaying;
}

void Arcade::Graph::Music::setIsPlaying(bool isPlaying)
{
    _isPlaying = isPlaying;
}

float Arcade::Graph::Music::getVolume() const
{
    return _volume;
}

void Arcade::Graph::Music::setVolume(float volume)
{
    _volume = volume;
}

void Arcade::Graph::Music::setPath(const std::string &path)
{
    _path = path;
}
