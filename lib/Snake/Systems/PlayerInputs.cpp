/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** PlayerInputs
*/

#include "PlayerInputs.hpp"
#include "Events.hpp"
#include "Movements.hpp"

void Snake::PlayerInputs::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    auto eventD = eventManager.isEventTriggered("KEY_DOWN_PRESSED");
    auto eventU = eventManager.isEventTriggered("KEY_UP_PRESSED");
    auto eventL = eventManager.isEventTriggered("KEY_LEFT_PRESSED");
    auto eventR = eventManager.isEventTriggered("KEY_RIGHT_PRESSED");

    if (!eventD.first && !eventU.first && !eventL.first && !eventR.first) {
        return;
    }
    auto &entities = currentScene.getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();
        enum Snake::Movements::Direction direction;

        if (idEntity.find("snake") == std::string::npos) {
            continue;
        }
        auto &movementsComp = entity->getComponents("Movements").front();
        if (eventD.first)
            direction = Snake::Movements::Direction::DOWN;
        if (eventU.first)
            direction = Snake::Movements::Direction::UP;
        if (eventL.first)
            direction = Snake::Movements::Direction::LEFT;
        if (eventR.first)
            direction = Snake::Movements::Direction::RIGHT;
        reinterpret_cast<Snake::Movements *>(movementsComp.get())->setDirection(direction);
    }
}
