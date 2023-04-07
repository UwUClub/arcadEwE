/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeTailManager
*/

#include "SnakeTailManager.hpp"
#include "Transform.hpp"
#include "IEntity.hpp"
#include "ObjectFactory.hpp"
#include "SnakeGameScene.hpp"
#include "Direction.hpp"
#include "ArcadeStruct.hpp"
#include <regex>
#include <string>
#include <iostream>

namespace Snake {
    void SnakeTailManager::run(double deltaTime,
        Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
    {
        (void)deltaTime;

        auto eatFruitEvent = eventManager.isEventTriggered("FRUIT_EATEN");
        if (eatFruitEvent.first) {
            auto entities = entityManager.getEntities();
            int snakeBodyCount= 0;

            for (auto &entity : entities) {
                std::string id = entity->getId();
                if (id.find("snake_body_") != std::string::npos) {
                    snakeBodyCount++;
                }
            }
            try {
                auto lastTail = entityManager.getEntitiesById("snake_body_" + std::to_string(snakeBodyCount - 1));
                if (lastTail == nullptr)
                    return;
                auto lastTailTransform = reinterpret_cast<Snake::Transform &>(lastTail->getComponents("Transform"));
                auto lastTailPos = lastTailTransform.getPosition();
                auto lastTailDirection = reinterpret_cast<Snake::Direction &>(lastTail->getComponents("Direction"));
                auto direction = lastTailDirection.getDirection();
                Arcade::Vector3f pos = lastTailPos;
                switch (direction) {
                    case Snake::Direction::UP:
                        pos.y += CASE_SIZE;
                        break;
                    case Snake::Direction::DOWN:
                        pos.y -= CASE_SIZE;
                        break;
                    case Snake::Direction::LEFT:
                        pos.x += CASE_SIZE;
                        break;
                    case Snake::Direction::RIGHT:
                        pos.x -= CASE_SIZE;
                        break;
                }
                auto objectFactory = Snake::ObjectFactory();
                objectFactory.CreateSnakeBody(entityManager, pos, {0, 0, 0});
            } catch (std::exception &e) {
                std::cerr << "Error: last tail not found" << std::endl;
            }
        }
    }
}
