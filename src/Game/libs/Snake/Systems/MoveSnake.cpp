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

            auto &position = reinterpret_cast<Snake::Transform &>(transformComp).position;
            auto speed = reinterpret_cast<Snake::Speed &>(speedComp).getSpeed();
            auto direction = reinterpret_cast<Snake::Direction &>(directionComp).getDirection();
            switch (direction) {
                case Snake::Direction::dir::UP:
                    position.y -= speed * deltaTime;
                    break;
                case Snake::Direction::dir::DOWN:
                    position.y += speed * deltaTime;
                    break;
                case Snake::Direction::dir::LEFT:
                    position.x -= speed * deltaTime;
                    break;
                case Snake::Direction::dir::RIGHT:
                    position.x += speed * deltaTime;
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveSnake, component not found" << std::endl;
            return;
        }
    }
}
