//
// Created by valegox on 30/03/23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "IEventManager.hpp"
#include "IEntityManager.hpp"
#include "Component.hpp"

namespace Arcade::Graph
{
    class SpriteHandler
    {
        public:
        SpriteHandler();
        ~SpriteHandler();

        void run(Arcade::ECS::IEntityManager &entityManager, sf::RenderWindow *window);
        void handleTexture(const std::string path, sf::Sprite *sprite);

        protected:
        std::map<std::string, sf::Texture *>
            _textures; // key is the texture path, value is the texture
    };
} // namespace Arcade::Graph
