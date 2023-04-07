//
// Created by valegox on 04/04/23.
//

#ifndef ARCADE_MUSIC_HPP
#define ARCADE_MUSIC_HPP

#include "GraphStruct.hpp"
#include "IComponent.hpp"
#include "IMusic.hpp"
#include "Component.hpp"

namespace Arcade::Game
{
    struct Music final : public Arcade::Graph::IMusic {
        public:
        Music(const std::string &id, const std::string &path, bool loop, bool play);
        ~Music() final = default;
    };
} // namespace Arcade::Game

#endif // ARCADE_MUSIC_HPP
