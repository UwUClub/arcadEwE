/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** PlayerInputs
*/

#include "PlayerInputs.hpp"
#include "Events.hpp"
#include "Sprite.hpp"
#include "Movements.hpp"

void Arcade::Core::PlayerInputs::run(std::size_t deltaTime,
    Arcade::ECS::IEventManager &eventManager, Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    auto eventD = eventManager.isEventTriggered("KEY_DOWN_PRESSED");
    auto eventU = eventManager.isEventTriggered("KEY_UP_PRESSED");
    auto eventL = eventManager.isEventTriggered("KEY_LEFT_PRESSED");
    auto eventR = eventManager.isEventTriggered("KEY_RIGHT_PRESSED");

    if (!eventD.first && !eventU.first && !eventL.first && !eventR.first) {
        return;
    }
    auto &entities = gameModule.getSceneManager().getCurrentScene()->getEntityManager().getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();
        enum Snake::Direction direction;

        if (idEntity.find("snake") == std::string::npos) {
            continue;
        }
        auto &spriteComp = entity->getComponents(ECS::CompType::MOVEMENT).front();
        if (eventD.first)
            direction = Snake::Direction::DOWN;
        if (eventU.first)
            direction = Snake::Direction::UP;
        if (eventL.first)
            direction = Snake::Direction::LEFT;
        if (eventR.first)
            direction = Snake::Direction::RIGHT;
        reinterpret_cast<Arcade::Graph::Movement *>(spriteComp.get())->setDirection(direction);
    }
}
