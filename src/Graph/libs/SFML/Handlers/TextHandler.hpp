//
// Created by valegox on 30/03/23.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "IEventManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Graph {
    class TextHandler
    {
        public:
        TextHandler() = default;
        ~TextHandler() = default;

        void run(Arcade::ECS::IEntityManager &entityManager, sf::RenderWindow &window);
        void handle_font(std::string path, sf::Text &text);

        protected:
        std::map<std::string, std::unique_ptr<sf::Font>> _fonts; // key is the font path, value is the font
    };
}
