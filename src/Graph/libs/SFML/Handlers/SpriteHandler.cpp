//
// Created by valegox on 30/03/23.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SFMLDisplayModule.hpp"
#include "SpriteHandler.hpp"
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "ISprite.hpp"

namespace Arcade::Graph
{

    SpriteHandler::SpriteHandler()
    {
        _textures = std::map<std::string, sf::Texture *>();
    }

    SpriteHandler::~SpriteHandler()
    {
        for (auto &texture : _textures) {
            if (texture.second != nullptr) {
                delete texture.second;
            }
        }
    }

    void SpriteHandler::run(Arcade::ECS::IEntityManager &entityManager, sf::RenderWindow *window)
    {
        for (auto &entity : entityManager.getEntities()) {

            if (entity->getComponents().find(Arcade::ECS::CompType::SPRITE) == entity->getComponents().end()) {
                continue;
            }

            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents
                = entity->getComponents(Arcade::ECS::CompType::SPRITE);

            for (auto spriteComponent : spriteComponents) {
                auto sprite = std::static_pointer_cast<Arcade::Graph::ISprite>(spriteComponent);

                sf::Sprite *sfSprite = new sf::Sprite();

                const int x = ((*sprite).pos.x / 100) * WINDOW_WIDTH;
                const int y = ((*sprite).pos.y / 100) * WINDOW_HEIGHT;
                sfSprite->setPosition(x, y);

                Arcade::Graph::Rect rect = (*sprite).rect;
                sfSprite->setTextureRect(sf::IntRect(rect.left + rect.width * sprite->currentRectIndex, rect.top, rect.width, rect.height));

                this->handleTexture((*sprite).path, sfSprite);

                window->draw(*sfSprite);
            }
        }
    }

    void SpriteHandler::handleTexture(const std::string path, sf::Sprite *sprite)
    {
        sf::Texture *texture = new sf::Texture();

        if (_textures.find(path) == _textures.end()) {
            if (texture->loadFromFile(path)) {
                _textures[path] = texture;
            } else {
                delete texture;
                texture = nullptr;
            }
        } else {
            texture = _textures[path];
        }

        if (texture != nullptr) {
            sprite->setTexture(*texture);
        }
    }

} // namespace Arcade::Graph
