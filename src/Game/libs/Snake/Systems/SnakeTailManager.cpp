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
#include "BoxCollider.hpp"
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
                std::string id = "snake_body_" + std::to_string(snakeBodyCount);
                if (!isTailValid(entityManager, id)) {
                    eventManager.addEvent("GAME_OVER");
                }
            } catch (std::exception &e) {
                std::cerr << "Error: last tail not found" << std::endl;
            }
        }
    }

    bool SnakeTailManager::isTailValid(Arcade::ECS::IEntityManager &entityManager, std::string &id) {
        auto entities = *entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::COLLIDER);
        auto tail = entityManager.getEntitiesById(id);
        if (tail == nullptr)
            return false;
        auto tailCollider = reinterpret_cast<BoxCollider &>(tail->getComponents("BoxCollider"));

        for (auto entity : entities) {
            if (entity == tail)
                continue;
            auto otherColliders = entity->getComponents(Arcade::ECS::CompType::COLLIDER);
            if (otherColliders.size() == 0 || !otherColliders[0])
                continue;
            auto &otherCollider = dynamic_cast<BoxCollider &>(*otherColliders[0]);
            if (!otherCollider.isEnabled)
                continue;
            if (tailCollider.IsColliding(otherCollider)) {
                return false;
            }
        }
        auto transformComp = reinterpret_cast<Transform &>(tail->getComponents("Transform"));
        auto pos = transformComp.getPosition();
        if (pos.x < 0 || pos.x > 100 - 1|| pos.y < 0 || pos.y > 100 - 1) {
            return false;
        }
        return true;
    }
}
