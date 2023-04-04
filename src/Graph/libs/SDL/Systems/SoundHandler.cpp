//
// Created by patatofour on 04/04/23.
//

#include <iostream>
#include "SoundHandler.hpp"

Mix_Chunk* Arcade::Graph::SoundHandler::loadSound(const std::string& path)
{
    Mix_Chunk* sound = nullptr;

    if (_sounds.find(path) != _sounds.end())
        return _sounds.at(path);
    sound = Mix_LoadWAV(path.c_str());
    if (sound == nullptr) {
        std::cerr << "Failed to load sound: " << path << std::endl;
        return nullptr;
    }
    _sounds.emplace(path, sound);
    return sound;
}

void Arcade::Graph::SoundHandler::loadMusic(const std::string& path)
{
    if (_music != nullptr) {
        Mix_HaltMusic();
        Mix_FreeMusic(_music);
        _music = nullptr;
    }
    _music = Mix_LoadMUS(path.c_str());
}

void Arcade::Graph::SoundHandler::playMusic(const std::shared_ptr<IMusic>& music)
{
    if (music->path.empty())
        return;
    loadMusic(music->path);
    Mix_PlayMusic(_music, music->loop ? -1 : 0);
    music->play = true;
}

void Arcade::Graph::SoundHandler::playSound(const std::shared_ptr<IMusic>& sound)
{
    if (sound->path.empty())
        return;
    Mix_Chunk* soundChunk = loadSound(sound->path);
    if (soundChunk == nullptr)
        return;
    Mix_PlayChannel(-1, soundChunk, sound->loop ? -1 : 0);
    sound->play = true;
}

void Arcade::Graph::SoundHandler::run(Arcade::ECS::IEntityManager& entityManager)
{
    auto musics = entityManager.getEntitiesByComponentType(ECS::CompType::MUSIC);

    for (auto& music : *musics) {
        auto& musicComps = music->getComponents(ECS::CompType::MUSIC);

        for (auto& musicComp : musicComps) {
            auto castedMusic = std::static_pointer_cast<IMusic>(musicComp);
            (castedMusic->id.find("music") != std::string::npos) ? playMusic(castedMusic)
                                                                 : playSound(castedMusic);
        }
    }
}

Arcade::Graph::SoundHandler::~SoundHandler()
{
    if (_music != nullptr) {
        Mix_HaltMusic();
        Mix_FreeMusic(_music);
        _music = nullptr;
    }
    for (auto& sound : _sounds) {
        Mix_FreeChunk(sound.second);
    }
}
