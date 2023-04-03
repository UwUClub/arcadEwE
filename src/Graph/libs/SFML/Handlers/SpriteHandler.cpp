//
// Created by valegox on 30/03/23.
//

#include <SFML/Graphics.hpp>
#include "SpriteHandler.hpp"
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IText.hpp"

namespace Arcade::Graph
{

    void SpriteHandler::run(double delta, Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
    {
        for (auto &entity : scene->getEntityManager().getEntities()) {

            if (entity->getComponents().find(Arcade::ECS::CompType::TEXT)
                == entity->getComponents().end()) {
                continue;
            }

            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents
                = entity->getComponents(Arcade::ECS::CompType::SPRITE);

            for (auto spriteComponent : spriteComponents) {
                auto sprite = std::static_pointer_cast<Arcade::Graph::ISprite>(spriteComponent);
                Arcade::Vector3f pos = (*sprite).getPos();
                Arcade::Vector3f size = (*sprite).getSize();
                Arcade::Graph::Rect rect = (*sprite).getRect();
                float scale = (*sprite).getScale();
                Arcade::Graph::Color color = (*sprite).getColor();

                sf::Texture texture;
                sf::Sprite sfSprite;
                sfSprite.setColor(sf::Color(color.r, color.g, color.b, color.a));
                if (texture.loadFromFile((*sprite).getPath())) {
                    sfSprite.setTexture(texture);
                }
                sfSprite.setPosition(pos.x, pos.y);
                sfSprite.setScale(size.x * scale, size.y * scale);
                sfSprite.setTextureRect(sf::IntRect(rect.left, rect.top, rect.width, rect.height));
                this->_window.draw(sfSprite);
            }
        }
    }
} // namespace Arcade::Graph
