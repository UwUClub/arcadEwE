/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** PlayerInputs
*/

#include "PlayerInputs.hpp"
#include "Events.hpp"
#include "Direction.hpp"
#include "SnakeSprite.hpp"
#include "Speed.hpp"
#include "SnakeGameScene.hpp"
#include "Transform.hpp"
#include "ObjectFactory.hpp"
#include <iostream>

void Snake::PlayerInputs::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    auto eventD = eventManager.isEventTriggered("KEY_DOWN_PRESSED");
    auto eventU = eventManager.isEventTriggered("KEY_UP_PRESSED");
    auto eventL = eventManager.isEventTriggered("KEY_LEFT_PRESSED");
    auto eventR = eventManager.isEventTriggered("KEY_RIGHT_PRESSED");

    (void)(deltaTime);
    if (!eventD.first && !eventU.first && !eventL.first && !eventR.first) {
        return;
    }
    auto &entities = currentScene.getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();
        enum Snake::Direction::dir direction = Snake::Direction::dir::UP;

        if (idEntity.find("snake") == std::string::npos) {
            continue;
        }
        try {
            auto &directionComp = entity->getComponents("Direction");

            if (eventU.first)
                direction = Snake::Direction::dir::UP;
            if (eventD.first)
                direction = Snake::Direction::dir::DOWN;
            if (eventL.first)
                direction = Snake::Direction::dir::LEFT;
            if (eventR.first)
                direction = Snake::Direction::dir::RIGHT;
            reinterpret_cast<Snake::Direction &>(directionComp).setNextDirection(direction);
            // SetNextPosition(*entity);

            if (idEntity.find("snake_head") != std::string::npos) {
                auto &spriteComp = entity->getComponents("Sprite");
                auto &sprite = reinterpret_cast<Snake::Sprite &>(spriteComp);

                if (eventU.first)
                    sprite.rect = { SNAKE_HEAD_SIZE * 3, 0, SNAKE_HEAD_SIZE, SNAKE_HEAD_SIZE };
                if (eventD.first)
                    sprite.rect = { SNAKE_HEAD_SIZE, 0, SNAKE_HEAD_SIZE, SNAKE_HEAD_SIZE };
                if (eventL.first)
                    sprite.rect = { SNAKE_HEAD_SIZE * 2, 0, SNAKE_HEAD_SIZE, SNAKE_HEAD_SIZE };
                if (eventR.first)
                    sprite.rect = { 0, 0, SNAKE_HEAD_SIZE, SNAKE_HEAD_SIZE };
            }

        } catch(const std::exception& e) {
            std::cerr << "playerInputs direction component not found" << std::endl;
            return;
        }
    }
}

void Snake::PlayerInputs::SetNextPosition(Arcade::ECS::IEntity &entity)
{
    auto &directionComp = entity.getComponents("Direction");
    auto &speedComp = entity.getComponents("Speed");
    auto &transformComp = entity.getComponents("Transform");
    auto &transform = reinterpret_cast<Snake::Transform &>(transformComp);
    auto nextPosition = reinterpret_cast<Snake::Speed &>(speedComp).getNextPoint();
    auto direction = reinterpret_cast<Snake::Direction &>(directionComp).getDirection();
    auto currentPos = transform.getPosition();
    currentPos.x = static_cast<int>(currentPos.x) / CASE_SIZE * CASE_SIZE;
    currentPos.y = static_cast<int>(currentPos.y) / CASE_SIZE * CASE_SIZE;

    switch (direction) {
        case Snake::Direction::dir::UP:
            nextPosition = {currentPos.x, currentPos.y - CASE_SIZE, 0};
            break;
        case Snake::Direction::dir::DOWN:
            nextPosition = {currentPos.x, currentPos.y + CASE_SIZE, 0};
            break;
        case Snake::Direction::dir::LEFT:
            nextPosition = {currentPos.x - CASE_SIZE, currentPos.y, 0};
            break;
        case Snake::Direction::dir::RIGHT:
            nextPosition = {currentPos.x + CASE_SIZE, currentPos.y, 0};
            break;
    }
    reinterpret_cast<Snake::Speed &>(speedComp).setNextPoint(nextPosition);
}