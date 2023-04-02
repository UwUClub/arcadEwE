/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameManager
*/

#include "SnakeGameManager.hpp"
#include "Events.hpp"
#include "Transform.hpp"

void Snake::SnakeGameManager::run(float deltaTime,
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
        auto &transformComp = entity->getComponents("Transform");
        auto &position = reinterpret_cast<Snake::Transform &>(transformComp).position;
        if (position.x < 0 || position.x > 1920 || position.y < 0 || position.y > 1080) {
            eventManager.addEvent("GAME_OVER");
        }
    }
}