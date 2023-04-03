//
// Created by patatofour on 28/03/23.
//

#include "MenuKeyboardHandler.hpp"
#include "IsHovered.hpp"
#include "Text.hpp"
#include "SelectionLib.hpp"

Snake::MenuKeyboardHandler::MenuKeyboardHandler()
{
}

void Snake::MenuKeyboardHandler::run([[maybe_unused]] double deltaTime,
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
        auto first = entities[0]->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0];
        auto &firstHover = reinterpret_cast<Arcade::Game::IsHovered &>(*first);
        firstHover.isHovered = true;
        return;
    }
    auto &hoveredEntityComp = reinterpret_cast<Arcade::Game::IsHovered &>(
        *hoveredEntity->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0]);
    auto &hoveredEntityText = reinterpret_cast<Arcade::Game::Text &>(
        *hoveredEntity->getComponents(Arcade::ECS::CompType::TEXT)[0]);

    for (auto &entity : entities) {
        if (keyUp.first) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0]);
            auto &textComp = reinterpret_cast<Arcade::Game::Text &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT)[0]);
            if (hoveredEntityText.pos.y + OFFSET_Y_TEXT == textComp.pos.y) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
                return;
            }
        }
        if (keyDown.first) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0]);
            auto &textComp = reinterpret_cast<Arcade::Game::Text &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT)[0]);
            if (hoveredEntityText.pos.y - OFFSET_Y_TEXT == textComp.pos.y) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
                return;
            }
        }
        if (keyLeft.first) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0]);
            auto &textComp = reinterpret_cast<Arcade::Game::Text &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT)[0]);
            if (hoveredEntityText.pos.x - OFFSET_X_TEXT == textComp.pos.x) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
                return;
            }
        }
        if (keyRight.first) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0]);
            auto &textComp = reinterpret_cast<Arcade::Game::Text &>(
                *entity->getComponents(Arcade::ECS::CompType::TEXT)[0]);
            if (hoveredEntityText.pos.x + OFFSET_X_TEXT == textComp.pos.x) {
                hoverComp.isHovered = true;
                hoveredEntityComp.isHovered = false;
                return;
            }
        }
    }
    if (keyEnter.first) {
        hoveredEntity = getCurrentlyHoveredEntity(currentEntityManager);
        hoveredEntityText = reinterpret_cast<Arcade::Game::Text &>(
            *hoveredEntity->getComponents(Arcade::ECS::CompType::TEXT)[0]);
        if (hoveredEntityText.text.find("PLAY") != std::string::npos) {
            eventManager.addEvent("PLAY",
                hoveredEntity->getComponents(Arcade::ECS::CompType::TEXT)[0]);
        }
    }
}

std::shared_ptr<Arcade::ECS::IEntity> Snake::MenuKeyboardHandler::getCurrentlyHoveredEntity(
    Arcade::ECS::IEntityManager &currentEntityManager)
{
    auto entities = currentEntityManager.getEntitiesByComponentType(Arcade::ECS::CompType::TEXT_HOVER);
    for (auto &entity : *entities) {
        auto &hover = entity->getComponents(Arcade::ECS::CompType::TEXT_HOVER)[0];
        if (hover) {
            auto &hoverComp = reinterpret_cast<Arcade::Game::IsHovered &>(*hover);
            if (hoverComp.isHovered)
                return entity;
        }
    }
    return nullptr;
}
