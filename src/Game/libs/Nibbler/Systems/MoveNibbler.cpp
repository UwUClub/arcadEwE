/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveNibbler
*/

#include "MoveNibbler.hpp"
#include "Events.hpp"
#include "Direction.hpp"
#include "Transform.hpp"
#include "Speed.hpp"
#include "NibblerGameScene.hpp"
#include <iostream>
#include <memory>
#include <iostream>

void Nibbler::MoveNibbler::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    (void)(eventManager);
    auto &entities = entityManager.getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("nibbler_head") == std::string::npos) {
            continue;
        }

        try {
            auto &transformComp = entity->getComponents("Transform");
            auto &directionComp = reinterpret_cast<Nibbler::Direction &>(entity->getComponents("Direction"));
            auto &speedComp = reinterpret_cast<Nibbler::Speed &>(entity->getComponents("Speed"));

            auto &transform = reinterpret_cast<Nibbler::Transform &>(transformComp);
            auto speed = speedComp.getSpeed();
            auto nextPos = speedComp.getNextPoint();
            auto direction = directionComp.getDirection();
            auto nextDirection = directionComp.getNextDirection();

            switch (direction) {
                case Nibbler::Direction::dir::UP:
                    transform.Translate({0, -speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y < nextPos.y) {
                        if (nextDirection != Nibbler::Direction::dir::UP && nextDirection != Nibbler::Direction::dir::DOWN) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("nibblerMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x, nextPos.y - CASE_SIZE, 0});
                        }
                    }
                    break;
                case Nibbler::Direction::dir::DOWN:
                    transform.Translate({0, speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y > nextPos.y) {
                        if (nextDirection != Nibbler::Direction::dir::DOWN && nextDirection != Nibbler::Direction::dir::UP) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("nibblerMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x, nextPos.y + CASE_SIZE, 0});
                        }
                    }
                    break;
                case Nibbler::Direction::dir::LEFT:
                    transform.Translate({-speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x < nextPos.x) {
                        if (nextDirection != Nibbler::Direction::dir::LEFT && nextDirection != Nibbler::Direction::dir::RIGHT) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("nibblerMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x - CASE_SIZE, nextPos.y, 0});
                        }
                    }
                    break;
                case Nibbler::Direction::dir::RIGHT:
                    transform.Translate({speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x > nextPos.x) {
                        if (nextDirection != Nibbler::Direction::dir::RIGHT && nextDirection != Nibbler::Direction::dir::LEFT) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(nextDirection);
                            eventManager.addEvent("nibblerMove");
                        } else {
                            speedComp.setNextPoint({nextPos.x + CASE_SIZE, nextPos.y, 0});
                        }
                    }
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveNibbler, component not found" << std::endl;
            return;
        }
    }
}
