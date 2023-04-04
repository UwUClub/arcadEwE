//
// Created by patatofour on 04/04/23.
//

#ifndef ARCADE_SPRITEDISPLAY_HPP
#define ARCADE_SPRITEDISPLAY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>
#include "ISprite.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph
{
    class SpriteDisplay
    {
        public:
        SpriteDisplay() = default;
        ~SpriteDisplay();

        void run(double delta, SDL_Renderer *renderer, Arcade::ECS::IEntityManager &entityManager);

        private:
        SDL_Texture *loadTexture(const std::string &path, SDL_Renderer *_renderer);
        void drawSprite(SDL_Renderer *renderer, const std::shared_ptr<ISprite> &sprite);
        std::unordered_map<std::string, SDL_Texture *> _textures;
    };
} // namespace Arcade::Graph

#endif // ARCADE_SPRITEDISPLAY_HPP
