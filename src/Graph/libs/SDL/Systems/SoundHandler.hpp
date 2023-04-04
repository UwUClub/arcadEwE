//
// Created by patatofour on 04/04/23.
//

#ifndef ARCADE_SOUNDHANDLER_HPP
#define ARCADE_SOUNDHANDLER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <unordered_map>
#include <string>
#include "IMusic.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph
{
    class SoundHandler
    {
        public:
        SoundHandler() = default;
        ~SoundHandler();

        void run(Arcade::ECS::IEntityManager &entityManager);

        private:
        void loadMusic(const std::string &path);
        void playMusic(const std::shared_ptr<IMusic> &music);
        void playSound(const std::shared_ptr<IMusic> &sound);
        Mix_Chunk *loadSound(const std::string &path);
        std::unordered_map<std::string, Mix_Chunk *> _sounds;
        Mix_Music *_music = nullptr;
    };
} // namespace Arcade::Graph

#endif // ARCADE_SOUNDHANDLER_HPP
