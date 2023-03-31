//
// Created by patatofour on 28/03/23.
//

#include "IsHovering.hpp"
#include "IsHovered.hpp"
#include "Text.hpp"
#include "IComponent.hpp"

Arcade::Game::IsHovering::IsHovering()
    : Arcade::ECS::ISystem()
{
}

void Arcade::Game::IsHovering::run([[maybe_unused]] float deltaTime,
    [[maybe_unused]] Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto entities = currentEntityManager.getEntitiesByComponentType(ECS::CompType::TEXT_HOVER);

    for (auto &entity : *entities) {
        auto &hover = entity->getComponents(ECS::CompType::TEXT_HOVER)[0];
        auto &text = entity->getComponents(ECS::CompType::TEXT)[0];

        if (hover && text) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(*hover);
            auto &textComp = reinterpret_cast<Arcade::Game::Text &>(*text);
            if (!hoverComp.isHovered) {
                textComp.textColor.r = 255;
                textComp.textColor.g = 255;
                textComp.textColor.b = 255;
                textComp.backgroundColor.r = 0;
                textComp.backgroundColor.g = 0;
                textComp.backgroundColor.b = 0;
                continue;
            }
            textComp.textColor.r = 0;
            textComp.textColor.g = 0;
            textComp.textColor.b = 0;
            textComp.backgroundColor.r = 255;
            textComp.backgroundColor.g = 255;
            textComp.backgroundColor.b = 255;
        }
    }
}
