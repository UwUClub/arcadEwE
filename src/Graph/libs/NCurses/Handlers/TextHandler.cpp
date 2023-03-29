//
// Created by valegox on 27/03/23.
//

#include <ncurses.h>
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IText.hpp"
#include "TextHandler.hpp"

namespace Arcade::Graph {

    TextHandler::TextHandler() : AHandler()
    {
    }

    void TextHandler::run([[maybe_unused]] float delta, [[maybe_unused]] Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
    {
        const std::vector<std::shared_ptr<Arcade::ECS::IEntity>> &entities = entityManager.getEntities();

        for (auto &entity : entities) {

            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

            for (auto textComponent : textComponents) {
                auto text = std::static_pointer_cast<IText>(textComponent);
                Arcade::Vector3f pos = (*text).pos;
                Color foregroundColor = (*text).textColor;
                Color backgroundColor = (*text).backgroundColor;

                printContent((*text).text, pos.x, pos.y, foregroundColor, backgroundColor);
            }
        }
    }
}
