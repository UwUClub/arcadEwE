/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** PlayerInputs
*/

#include "PlayerInputs.hpp"
#include "Events.hpp"
#include "Direction.hpp"

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
        auto &directionComp = entity->getComponents("Direction");
        if (eventD.first)
            direction = Snake::Direction::dir::DOWN;
        if (eventU.first)
            direction = Snake::Direction::dir::UP;
        if (eventL.first)
            direction = Snake::Direction::dir::LEFT;
        if (eventR.first)
            direction = Snake::Direction::dir::RIGHT;
        reinterpret_cast<Snake::Direction &>(directionComp).setDirection(direction);
    }
}
