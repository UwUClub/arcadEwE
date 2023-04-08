/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** PlayerInputs
*/

#include "PlayerInputs.hpp"
#include "Events.hpp"
#include "Direction.hpp"
#include "Speed.hpp"
#include "NibblerGameScene.hpp"
#include "Transform.hpp"
#include <iostream>

void Nibbler::PlayerInputs::run(double deltaTime,
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
        enum Nibbler::Direction::dir direction = Nibbler::Direction::dir::UP;

        if (idEntity.find("nibbler") == std::string::npos) {
            continue;
        }
        try {
            auto &directionComp = entity->getComponents("Direction");

            if (eventU.first)
                direction = Nibbler::Direction::dir::UP;
            if (eventD.first)
                direction = Nibbler::Direction::dir::DOWN;
            if (eventL.first)
                direction = Nibbler::Direction::dir::LEFT;
            if (eventR.first)
                direction = Nibbler::Direction::dir::RIGHT;
            reinterpret_cast<Nibbler::Direction &>(directionComp).setNextDirection(direction);
            // SetNextPosition(*entity);
        } catch(const std::exception& e) {
            std::cerr << "playerInputs direction component not found" << std::endl;
            return;
        }
    }
}

void Nibbler::PlayerInputs::SetNextPosition(Arcade::ECS::IEntity &entity)
{
    auto &directionComp = entity.getComponents("Direction");
    auto &speedComp = entity.getComponents("Speed");
    auto &transformComp = entity.getComponents("Transform");
    auto &transform = reinterpret_cast<Nibbler::Transform &>(transformComp);
    auto nextPosition = reinterpret_cast<Nibbler::Speed &>(speedComp).getNextPoint();
    auto direction = reinterpret_cast<Nibbler::Direction &>(directionComp).getDirection();
    auto currentPos = transform.getPosition();
    currentPos.x = static_cast<int>(currentPos.x) / CASE_SIZE * CASE_SIZE;
    currentPos.y = static_cast<int>(currentPos.y) / CASE_SIZE * CASE_SIZE;

    switch (direction) {
        case Nibbler::Direction::dir::UP:
            nextPosition = {currentPos.x, currentPos.y - CASE_SIZE, 0};
            break;
        case Nibbler::Direction::dir::DOWN:
            nextPosition = {currentPos.x, currentPos.y + CASE_SIZE, 0};
            break;
        case Nibbler::Direction::dir::LEFT:
            nextPosition = {currentPos.x - CASE_SIZE, currentPos.y, 0};
            break;
        case Nibbler::Direction::dir::RIGHT:
            nextPosition = {currentPos.x + CASE_SIZE, currentPos.y, 0};
            break;
    }
    reinterpret_cast<Nibbler::Speed &>(speedComp).setNextPoint(nextPosition);
}