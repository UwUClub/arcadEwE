//
// Created by patatofour on 21/03/23.
//

#include "Music.hpp"

#include <utility>

Arcade::Graph::Music::Music(std::string path, std::string id) :
    _path(std::move(path)),
    _id(std::move(id)),
    _loop(false),
    _isPlaying(false),
    _volume(100)
{
}

const std::string &Arcade::Graph::Music::getPath() const
{
    return _path;
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
