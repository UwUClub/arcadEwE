/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveTail
*/

#include "MoveTail.hpp"
#include "Events.hpp"
#include "Direction.hpp"
#include "Transform.hpp"
#include "Speed.hpp"
#include "NibblerGameScene.hpp"
#include "NibblerPath.hpp"
#include <iostream>
#include <memory>
#include <vector>

void Nibbler::MoveTail::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto isMoved = eventManager.isEventTriggered("nibblerMove");
    auto nibblerHead = entityManager.getEntitiesById("nibbler_head");
    if (nibblerHead == nullptr) {
        return;
    }
    auto &headTransformComp = reinterpret_cast<Nibbler::Transform &>(nibblerHead->getComponents("Transform"));
    auto headPosition = headTransformComp.getPosition();
    auto &headDirectionComp = reinterpret_cast<Nibbler::Direction &>(nibblerHead->getComponents("Direction"));
    auto headDirection = headDirectionComp.getDirection();

    auto &entities = entityManager.getEntities();
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("nibbler_body") == std::string::npos) {
            continue;
        }
        try {
            auto &transformComp = entity->getComponents("Transform");
            auto &directionComp = reinterpret_cast<Nibbler::Direction &>(entity->getComponents("Direction"));
            auto &speedComp = reinterpret_cast<Nibbler::Speed &>(entity->getComponents("Speed"));

            auto &transform = reinterpret_cast<Nibbler::Transform &>(transformComp);
            auto speed = speedComp.getSpeed();
            auto direction = directionComp.getDirection();
            auto &pathComp = reinterpret_cast<Nibbler::NibblerPath &>(entity->getComponents("NibblerPath"));
            auto nextPoint = pathComp.getPoint();

            if (isMoved.first) {
                pathComp.addPoint(headDirection, headPosition);
            }

            switch (direction) {
                case Nibbler::Direction::dir::UP:
                    transform.Translate({0, -speed * static_cast<float>(deltaTime), 0});
                    if (nextPoint.second.y != -1 && transform.getPosition().y < nextPoint.second.y) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
                case Nibbler::Direction::dir::DOWN:
                    transform.Translate({0, speed * static_cast<float>(deltaTime), 0});
                    if (nextPoint.second.y != -1 && transform.getPosition().y > nextPoint.second.y) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
                case Nibbler::Direction::dir::LEFT:
                    transform.Translate({-speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPoint.second.x != -1 && transform.getPosition().x < nextPoint.second.x) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
                case Nibbler::Direction::dir::RIGHT:
                    transform.Translate({speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPoint.second.x != -1 && transform.getPosition().x > nextPoint.second.x) {
                        transform.setPosition(nextPoint.second);
                        directionComp.setDirection(nextPoint.first);
                        pathComp.popPoint();
                    }
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveTail, component not found" << std::endl;
            return;
        }
    }
}
