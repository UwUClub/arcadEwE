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
#include <iostream>

void Snake::MoveSnake::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    (void)(eventManager);
    auto &entities = currentScene.getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("snake") == std::string::npos) {
            continue;
        }

        try {
            auto &transformComp = entity->getComponents("Transform");
            auto &directionComp = entity->getComponents("Direction");
            auto &speedComp = entity->getComponents("Speed");

            auto &transform = reinterpret_cast<Snake::Transform &>(transformComp);
            auto speed = reinterpret_cast<Snake::Speed &>(speedComp).getSpeed();
            auto nextPos = reinterpret_cast<Snake::Speed &>(speedComp).getNextPoint();
            auto direction = reinterpret_cast<Snake::Direction &>(directionComp).getDirection();
            switch (direction) {
                case Snake::Direction::dir::UP:
                    transform.Translate({0, -speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y < nextPos.y) {
                        transform.setPosition(nextPos);
                        reinterpret_cast<Snake::Speed &>(speedComp).setNextPoint({-1, -1, -1});
                    }
                    break;
                case Snake::Direction::dir::DOWN:
                    transform.Translate({0, speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y > nextPos.y) {
                        transform.setPosition(nextPos);
                        reinterpret_cast<Snake::Speed &>(speedComp).setNextPoint({-1, -1, -1});
                    }
                    break;
                case Snake::Direction::dir::LEFT:
                    transform.Translate({-speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x < nextPos.x) {
                        transform.setPosition(nextPos);
                        reinterpret_cast<Snake::Speed &>(speedComp).setNextPoint({-1, -1, -1});
                    }
                    break;
                case Snake::Direction::dir::RIGHT:
                    transform.Translate({speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x > nextPos.x) {
                        transform.setPosition(nextPos);
                        reinterpret_cast<Snake::Speed &>(speedComp).setNextPoint({-1, -1, -1});
                    }
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveSnake, component not found" << std::endl;
            return;
        }
    }
}
