//
// Created by valegox on 27/03/23.
//

#include <iostream>
#include <ncurses.h>
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IText.hpp"
#include "TextHandler.hpp"

namespace Arcade::Graph
{

    TextHandler::TextHandler()
    {
    }

    void TextHandler::run([[maybe_unused]] float delta,
        [[maybe_unused]] Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
    {
        auto entities = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::TEXT);

        for (auto &entity : *entities) {
            auto &textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

            for (auto &textComponent : textComponents) {
                auto text = std::static_pointer_cast<IText>(textComponent);
                Arcade::Vector3f pos = (*text).pos;
                Color foregroundColor = (*text).textColor;
                Color backgroundColor = (*text).backgroundColor;

                this->printContent((*text).text, pos.x, pos.y, foregroundColor, backgroundColor);
            }
        }
    }
} // namespace Arcade::Graph
