//
// Created by valegox on 04/04/23.
//

#pragma once

#include <SFML/Audio.hpp>
#include <string>
#include <map>
#include <memory>
#include "IEntityManager.hpp"
#include "Component.hpp"

namespace Arcade::Graph
{
    class MusicHandler
    {
        public:
        MusicHandler() = default;
        ~MusicHandler() = default;

        void run(Arcade::ECS::IEntityManager &entityManager);

        protected:
        std::map<std::string, std::unique_ptr<sf::Music>> _playingMusics; // key is music id
    };
} // namespace Arcade::Graph
