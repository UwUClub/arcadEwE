//
// Created by patatofour on 04/04/23.
//

#ifndef ARCADE_TEXTHANDLER_HPP
#define ARCADE_TEXTHANDLER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <unordered_map>
#include <string>
#include "IText.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph
{
    class TextHandler
    {
        public:
        TextHandler();
        ~TextHandler();

        void run(SDL_Renderer *renderer, Arcade::ECS::IEntityManager &entityManager);

        private:
        TTF_Font *loadFont(const std::string &path);
        void drawText(SDL_Renderer *renderer, const std::shared_ptr<IText> &text);
        std::unordered_map<std::string, TTF_Font *> _fonts;
    };
} // namespace Arcade::Graph
#endif // ARCADE_TEXTHANDLER_HPP
