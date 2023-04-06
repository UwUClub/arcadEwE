/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveSnake
*/

#include "MoveSnake.hpp"
#include "Events.hpp"
#include "Direction.hpp"
#include "Transform.hpp"
#include "Speed.hpp"
#include "SnakeGameScene.hpp"
#include <iostream>
#include <memory>

void Snake::MoveSnake::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    (void)(eventManager);
    auto &entities = entityManager.getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("snake_head") == std::string::npos) {
            continue;
        }

        try {
            auto &transformComp = entity->getComponents("Transform");
            auto &directionComp = reinterpret_cast<Snake::Direction &>(entity->getComponents("Direction"));
            auto &speedComp = reinterpret_cast<Snake::Speed &>(entity->getComponents("Speed"));

            auto &transform = reinterpret_cast<Snake::Transform &>(transformComp);
            auto speed = speedComp.getSpeed();
            auto nextPos = speedComp.getNextPoint();
            auto direction = directionComp.getDirection();
            auto nextDirection = directionComp.getNextDirection();

            switch (direction) {
                case Snake::Direction::dir::UP:
                    transform.Translate({0, -speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y < nextPos.y) {
                        if (nextDirection != Snake::Direction::dir::UP && nextDirection != Snake::Direction::dir::DOWN) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("SnakeMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x, nextPos.y - CASE_SIZE, 0});
                        }
                    }
                    break;
                case Snake::Direction::dir::DOWN:
                    transform.Translate({0, speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y > nextPos.y) {
                        if (nextDirection != Snake::Direction::dir::DOWN && nextDirection != Snake::Direction::dir::UP) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("SnakeMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x, nextPos.y + CASE_SIZE, 0});
                        }
                    }
                    break;
                case Snake::Direction::dir::LEFT:
                    transform.Translate({-speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x < nextPos.x) {
                        if (nextDirection != Snake::Direction::dir::LEFT && nextDirection != Snake::Direction::dir::RIGHT) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("SnakeMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x - CASE_SIZE, nextPos.y, 0});
                        }
                    }
                    break;
                case Snake::Direction::dir::RIGHT:
                    transform.Translate({speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x > nextPos.x) {
                        if (nextDirection != Snake::Direction::dir::RIGHT && nextDirection != Snake::Direction::dir::LEFT) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("SnakeMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x + CASE_SIZE, nextPos.y, 0});
                        }
                    }
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveSnake, component not found" << std::endl;
            return;
        }
    }
}
