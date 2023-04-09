/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameManager
*/

#include "NibblerGameManager.hpp"
#include "Events.hpp"
#include "Transform.hpp"
#include "Direction.hpp"
#include "NibblerGameScene.hpp"
#include <iostream>

void Nibbler::NibblerGameManager::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &currentScene)
{
    auto &entities = currentScene.getEntities();

    (void)(deltaTime);
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity != "nibbler_head") {
            continue;
        }
        try {
            (void)eventManager;
            // const int shift = 2;
            // auto &transformComp = entity->getComponents("Transform");
            // auto &directionComp = entity->getComponents("Direction");

            // auto &position = reinterpret_cast<Nibbler::Transform &>(transformComp).position;
            // const auto direction = reinterpret_cast<Nibbler::Direction &>(directionComp).getDirection();

            // if (position.x < 0 + shift && direction == Nibbler::Direction::dir::LEFT) {
            //     eventManager.addEvent("KEY_DOWN_PRESSED");
            // }
            // if (position.x > 100 - 12 && direction == Nibbler::Direction::dir::RIGHT) {
            //     eventManager.addEvent("KEY_UP_PRESSED");
            // }
            // if (position.y < 0 + shift && direction == Nibbler::Direction::dir::UP) {
            //     eventManager.addEvent("KEY_LEFT_PRESSED");
            // }
            // if (position.y > 100 - 20 && direction == Nibbler::Direction::dir::DOWN) {
            //     eventManager.addEvent("KEY_RIGHT_PRESSED");
            // }
        } catch (const std::exception &e) {
            std::cerr << "nibblerGameManager, component not found" << std::endl;
            return;
        }
    }
}
