/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveTail
*/

#include "MoveTail.hpp"
#include "Events.hpp"
#include "Direction.hpp"
#include "Transform.hpp"
#include "Speed.hpp"
#include "SnakeGameScene.hpp"
#include "SnakePath.hpp"
#include <iostream>
#include <memory>
#include <vector>

void Snake::MoveTail::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto isMoved = eventManager.isEventTriggered("SnakeMove");
    auto snakeHead = entityManager.getEntitiesById("snake_head");
    if (snakeHead == nullptr) {
        return;
    }
    auto &headTransformComp = reinterpret_cast<Snake::Transform &>(snakeHead->getComponents("Transform"));
    auto headPosition = headTransformComp.getPosition();
    auto &headDirectionComp = reinterpret_cast<Snake::Direction &>(snakeHead->getComponents("Direction"));
    auto headDirection = headDirectionComp.getDirection();

    auto &entities = entityManager.getEntities();
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("snake_body") == std::string::npos) {
            continue;
        }
        try {
            auto &transformComp = entity->getComponents("Transform");
            auto &directionComp = reinterpret_cast<Snake::Direction &>(entity->getComponents("Direction"));
            auto &speedComp = reinterpret_cast<Snake::Speed &>(entity->getComponents("Speed"));

            auto &transform = reinterpret_cast<Snake::Transform &>(transformComp);
            auto speed = speedComp.getSpeed();
            auto direction = directionComp.getDirection();
            auto &pathComp = reinterpret_cast<Snake::SnakePath &>(entity->getComponents("SnakePath"));
            auto nextPoint = pathComp.getPoint();

            if (isMoved.first) {
                pathComp.addPoint(headDirection, headPosition);
            }

            switch (direction) {
                case Snake::Direction::dir::UP:
                    transform.Translate({0, -speed * static_cast<float>(deltaTime), 0});
                    if (nextPoint.second.y != -1 && transform.getPosition().y < nextPoint.second.y) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
                case Snake::Direction::dir::DOWN:
                    transform.Translate({0, speed * static_cast<float>(deltaTime), 0});
                    if (nextPoint.second.y != -1 && transform.getPosition().y > nextPoint.second.y) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
                case Snake::Direction::dir::LEFT:
                    transform.Translate({-speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPoint.second.x != -1 && transform.getPosition().x < nextPoint.second.x) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
                case Snake::Direction::dir::RIGHT:
                    transform.Translate({speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPoint.second.x != -1 && transform.getPosition().x > nextPoint.second.x) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveTail, component not found" << std::endl;
            return;
        }
    }
}
