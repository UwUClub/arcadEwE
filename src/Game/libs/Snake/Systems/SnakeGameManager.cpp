/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameManager
*/

#include "SnakeGameManager.hpp"
#include "Events.hpp"
#include "Transform.hpp"
#include "SnakeGameScene.hpp"
#include <iostream>

void Snake::SnakeGameManager::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    auto &entities = currentScene.getEntities();

    (void)(deltaTime);
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity != "snake_head") {
            continue;
        }
        try {
            auto &transformComp = entity->getComponents("Transform");

            auto &position = reinterpret_cast<Snake::Transform &>(transformComp).position;
            if (position.x < 0 || position.x > 100 - 1 || position.y < 0 || position.y > 100 - 1) {
                eventManager.addEvent("GAME_OVER");
            }
        } catch (const std::exception &e) {
            std::cerr << "snakeGameManager, component not found" << std::endl;
            return;
        }
    }
}
