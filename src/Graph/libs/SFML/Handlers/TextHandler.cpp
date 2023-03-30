//
// Created by valegox on 30/03/23.
//

#include <SFML/Graphics.hpp>
#include "TextHandler.hpp"
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IText.hpp"

namespace Arcade::Graph {

    void TextHandler::run([[maybe_unused]] Arcade::ECS::IEntityManager &entityManager, [[maybe_unused]] sf::RenderWindow &window)
    {
        for (auto &entity : entityManager.getEntities()) {

            if (entity->getComponents().find(Arcade::ECS::CompType::TEXT) == entity->getComponents().end()) {
                continue;
            }

            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

            for (auto textComponent : textComponents) {
                auto text = std::static_pointer_cast<Arcade::Graph::IText>(textComponent);
                Arcade::Graph::Color fColor = (*text).textColor;
                Arcade::Graph::Color bColor = (*text).backgroundColor;

                sf::Text sfText;
                sfText.setFillColor(sf::Color(fColor.r, fColor.g, fColor.b, fColor.a));
                sfText.setOutlineColor(sf::Color(bColor.r, bColor.g, bColor.b, bColor.a));

                this->handle_font((*text).fontPath, sfText);

                sfText.setPosition((*text).pos.x, (*text).pos.y);
                sfText.setString((*text).text);
                // sfText.setCharacterSize((*text).policeSize);
                window.draw(sfText);
            }
        }
    }

    void TextHandler::handle_font(std::string path, [[maybe_unused]] sf::Text &text)
    {
        sf::Font font;

        if (_fonts.find(path) == _fonts.end()) {
            if (font.loadFromFile(path)) {
                _fonts[path] = std::make_unique<sf::Font>(font);
            } else {
                _fonts[path] = nullptr;
            }
        }
        if (_fonts[path] != nullptr) {
            text.setFont(*(_fonts[path]));
        } else {
            // TODO: set default font
        }
    }
}
