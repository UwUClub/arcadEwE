//
// Created by patatofour on 28/03/23.
//

#include <iostream>
#include "KeyboardHandler.hpp"
#include "IsHovered.hpp"
#include "Core.hpp"
#include "Text.hpp"
#include "SelectionLib.hpp"
#include "IComponent.hpp"

Arcade::Game::KeyboardHandler::KeyboardHandler()
{
}

void Arcade::Game::KeyboardHandler::run([[maybe_unused]] double deltaTime,
    Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto keyUp = eventManager.isEventTriggered(KEY_UP_PRESSED);
    auto keyDown = eventManager.isEventTriggered(KEY_DOWN_PRESSED);
    auto keyLeft = eventManager.isEventTriggered(KEY_LEFT_PRESSED);
    auto keyRight = eventManager.isEventTriggered(KEY_RIGHT_PRESSED);
    auto keyEnter = eventManager.isEventTriggered(KEY_ENTER_PRESSED);
    auto &entities = currentEntityManager.getEntities();
    auto hoveredEntity = getCurrentlyHoveredEntity(currentEntityManager);

    if (!hoveredEntity) {
        auto first = entities[0]->getComponents(ECS::CompType::TEXT_HOVER)[0];
        auto &firstHover = reinterpret_cast<Arcade::Game::IsHovered &>(*first);
        firstHover.isHovered = true;
        return;
    }
    hoveredEntity = getCurrentlyHoveredEntity(currentEntityManager);
    auto &hoveredEntityComp = reinterpret_cast<Arcade::Game::IsHovered &>(
        *hoveredEntity->getComponents(ECS::CompType::TEXT_HOVER)[0]);
    auto &hoveredEntityText = reinterpret_cast<Arcade::Game::Text &>(
        *hoveredEntity->getComponents(ECS::CompType::TEXT)[0]);

    for (auto &entity : entities) {

        if (entity->getComponents().find(ECS::CompType::TEXT_HOVER) == entity->getComponents().end() ||
            entity->getComponents().find(ECS::CompType::TEXT) == entity->getComponents().end()) {
            continue;
        }

        auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(
            *entity->getComponents(ECS::CompType::TEXT_HOVER)[0]);
        auto &textComp = reinterpret_cast<Arcade::Game::Text &>(
            *entity->getComponents(ECS::CompType::TEXT)[0]);

        if (keyUp.first) {
            if (hoveredEntityText.pos.y - OFFSET_Y_TEXT == textComp.pos.y
                && hoveredEntityText.pos.x == textComp.pos.x) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
            }
        }
        if (keyDown.first) {
            if (hoveredEntityText.pos.y + OFFSET_Y_TEXT == textComp.pos.y
                && hoveredEntityText.pos.x == textComp.pos.x) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
            }
        }
        if (keyLeft.first) {
            if (hoveredEntityText.pos.x - OFFSET_X_TEXT == textComp.pos.x
                && hoveredEntityText.pos.y == textComp.pos.y) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
            }
        }
        if (keyRight.first) {
            if (hoveredEntityText.pos.x + OFFSET_X_TEXT == textComp.pos.x
                && hoveredEntityText.pos.y == textComp.pos.y) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
            }
        }
    }
    if (keyEnter.first) {
        hoveredEntity = getCurrentlyHoveredEntity(currentEntityManager);
        hoveredEntityText = reinterpret_cast<Arcade::Game::Text &>(
            *hoveredEntity->getComponents(ECS::CompType::TEXT)[0]);
        auto text = std::make_shared<Arcade::Game::Text>(
            Arcade::Game::Text(hoveredEntityText.id, hoveredEntityText.text, FONT_PATH,
                { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X_TEXT, 0, 0 }));
        if (hoveredEntityText.text.find("_game") == std::string::npos) {
            eventManager.addEvent(CHANGE_GRAPHIC, text);
        }
    }
}

std::shared_ptr<Arcade::ECS::IEntity> Arcade::Game::KeyboardHandler::getCurrentlyHoveredEntity(
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto entities = currentEntityManager.getEntitiesByComponentType(ECS::CompType::TEXT_HOVER);
    for (auto &entity : *entities) {
        auto &hover = entity->getComponents(ECS::CompType::TEXT_HOVER)[0];
        if (hover) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(*hover);
            if (hoverComp.isHovered)
                return entity;
        }
    }
    return nullptr;
}
