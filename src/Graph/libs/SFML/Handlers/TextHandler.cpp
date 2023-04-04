//
// Created by valegox on 30/03/23.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SFMLDisplayModule.hpp"
#include "TextHandler.hpp"
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IText.hpp"

namespace Arcade::Graph {

    TextHandler::TextHandler()
    {
        _fonts = std::map<std::string, sf::Font *>();
        _fonts["assets/fonts/arial.ttf"] = new sf::Font();
        if (!_fonts["assets/fonts/arial.ttf"]->loadFromFile("assets/fonts/arial.ttf")) {
            delete _fonts["assets/fonts/arial.ttf"];
            _fonts["assets/fonts/arial.ttf"] = nullptr;
        }
    }

    void TextHandler::run(Arcade::ECS::IEntityManager &entityManager, sf::RenderWindow *window)
    {
        for (auto &entity : entityManager.getEntities()) {

            if (entity->getComponents().find(Arcade::ECS::CompType::TEXT) == entity->getComponents().end()) {
                std::cout << "continue" << std::endl;
                continue;
            }

            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

            for (auto textComponent : textComponents) {
                auto text = std::static_pointer_cast<Arcade::Graph::IText>(textComponent);
                Arcade::Graph::Color fColor = (*text).textColor;
                Arcade::Graph::Color bColor = (*text).backgroundColor;

                sf::Text *sfText = new sf::Text();
                sfText->setString((*text).text);
                sfText->setOutlineThickness(5);
                sfText->setFillColor(sf::Color(fColor.r, fColor.g, fColor.b, fColor.a));
                sfText->setOutlineColor(sf::Color(bColor.r, bColor.g, bColor.b, bColor.a));

                this->handle_font((*text).fontPath, sfText);

                const int x = ((*text).pos.x / 100) * WINDOW_WIDTH;
                const int y = ((*text).pos.y / 100) * WINDOW_HEIGHT;
                sfText->setPosition(x, y);
                sfText->setCharacterSize(20);
                window->draw(*sfText);
            }
        }
    }

    void TextHandler::handle_font(std::string path, sf::Text *text)
    {
        sf::Font *font = new sf::Font();

        if (_fonts.find(path) == _fonts.end()) {
            if (font->loadFromFile(path)) {
                _fonts[path] = font;
            } else {
                _fonts[path] = nullptr;
            }
        }
        if (_fonts[path] != nullptr) {
            text->setFont(*(_fonts[path]));
        } else if (_fonts.find("assets/fonts/arial.ttf") != _fonts.end()) {
            text->setFont(*(_fonts["assets/fonts/arial.ttf"]));
        }
    }
}
