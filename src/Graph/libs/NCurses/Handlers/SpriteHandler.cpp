//
// Created by valegox on 22/03/23.
//

#include <ncurses.h>
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "ISprite.hpp"
#include "SpriteHandler.hpp"

namespace Arcade::Graph {

    SpriteHandler::SpriteHandler()
    {
    }

    void SpriteHandler::run([[maybe_unused]] float delta, [[maybe_unused]] Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
    {
        const std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &entities = entityManager.getEntities();

        for (auto &entity : entities) {

            if (entity->getComponents().find(Arcade::ECS::CompType::SPRITE) == entity->getComponents().end()) {
                continue;
            }
    
            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents = entity->getComponents(Arcade::ECS::CompType::SPRITE);

            for (auto spriteComponent : spriteComponents) {
                auto sprite = std::static_pointer_cast<ISprite>(spriteComponent);
                Arcade::Vector3f pos = (*sprite).pos;
                TTYData data = (*sprite).ttyData;

                this->printContent(data.defaultChar, pos.x, pos.y, data.foreground, data.background);
            }
        }
    }
}
