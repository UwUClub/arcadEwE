//
// Created by valegox on 30/03/23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "IEntityManager.hpp"

namespace Arcade::Graph {
    class TextHandler
    {
        public:
        TextHandler();
        ~TextHandler();

        void run(Arcade::ECS::IEntityManager &entityManager, sf::RenderWindow *window);
        void handleFont(std::string path, sf::Text *text);

        protected:
        std::map<std::string, sf::Font *> _fonts; // key is the font path, value is the font
    };
}
