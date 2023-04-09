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
#include "BoxCollider.hpp"
#include "NibblerHeadCollider.hpp"
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
                        bool isUpValid = IsUpValid(entityManager, *entity, nextPos);
                        bool isRightValid = IsRightValid(entityManager, *entity, nextPos);
                        bool isLeftValid = IsLeftValid(entityManager, *entity, nextPos);

                        if (nextDirection == Nibbler::Direction::dir::LEFT && isLeftValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::LEFT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (nextDirection == Nibbler::Direction::dir::RIGHT && isRightValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::RIGHT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isUpValid) {
                            speedComp.setNextPoint({nextPos.x, nextPos.y - CASE_SIZE, 0});
                            return;
                        }
                        if (isLeftValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::LEFT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isRightValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::RIGHT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        std::cerr << "no valid direction" << std::endl;
                    }
                    break;
                case Nibbler::Direction::dir::DOWN:
                    transform.Translate({0, speed * static_cast<float>(deltaTime), 0});
                    if (nextPos.y != -1 && transform.getPosition().y > nextPos.y) {
                        bool isDownValid = IsDownValid(entityManager, *entity, nextPos);
                        bool isRightValid = IsRightValid(entityManager, *entity, nextPos);
                        bool isLeftValid = IsLeftValid(entityManager, *entity, nextPos);

                        if (nextDirection == Nibbler::Direction::dir::LEFT && isLeftValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::LEFT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (nextDirection == Nibbler::Direction::dir::RIGHT && isRightValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::RIGHT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isDownValid) {
                            speedComp.setNextPoint({nextPos.x, nextPos.y + CASE_SIZE, 0});
                            return;
                        }
                        if (isLeftValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::LEFT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isRightValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::RIGHT);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        std::cerr << "no valid direction" << std::endl;
                    }
                    break;
                case Nibbler::Direction::dir::LEFT:
                    transform.Translate({-speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x < nextPos.x) {
                        bool isUpValid = IsUpValid(entityManager, *entity, nextPos);
                        bool isDownValid = IsDownValid(entityManager, *entity, nextPos);
                        bool isLeftValid = IsLeftValid(entityManager, *entity, nextPos);

                        if (nextDirection == Nibbler::Direction::dir::UP && isUpValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::UP);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (nextDirection == Nibbler::Direction::dir::DOWN && isDownValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::DOWN);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isLeftValid) {
                            speedComp.setNextPoint({nextPos.x - CASE_SIZE, nextPos.y, 0});
                            return;
                        }
                        if (isUpValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::UP);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isDownValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::DOWN);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        std::cerr << "no valid direction" << std::endl;
                    }
                    break;
                case Nibbler::Direction::dir::RIGHT:
                    transform.Translate({speed * static_cast<float>(deltaTime), 0, 0});
                    if (nextPos.x != -1 && transform.getPosition().x > nextPos.x) {
                        bool isUpValid = IsUpValid(entityManager, *entity, nextPos);
                        bool isDownValid = IsDownValid(entityManager, *entity, nextPos);
                        bool isRightValid = IsRightValid(entityManager, *entity, nextPos);

                        if (nextDirection == Nibbler::Direction::dir::UP && isUpValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::UP);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (nextDirection == Nibbler::Direction::dir::DOWN && isDownValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::DOWN);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isRightValid) {
                            speedComp.setNextPoint({nextPos.x + CASE_SIZE, nextPos.y, 0});
                            return;
                        }
                        if (isUpValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::UP);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        if (isDownValid) {
                            transform.setPosition(nextPos);
                            directionComp.setDirection(Nibbler::Direction::dir::DOWN);
                            eventManager.addEvent("nibblerMove");
                            return;
                        }
                        std::cerr << "no valid direction" << std::endl;
                    }
                    break;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveNibbler, component not found" << std::endl;
            return;
        }
    }
}

bool Nibbler::MoveNibbler::IsUpValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position)
{
    auto &entities = entityManager.getEntities();
    auto &colliderComp = reinterpret_cast<Nibbler::NibblerHeadCollider &>(nibbler.getComponents("NibblerCollider"));
    auto &transformComp = reinterpret_cast<Nibbler::Transform &>(nibbler.getComponents("Transform"));

    auto tmpPos = position;
    tmpPos.y -= WALL_OFFSET_Y;
    if (tmpPos.y < 0)
        return false;
    transformComp.setPosition(tmpPos);
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("wall") == std::string::npos) {
            continue;
        }

        try {
            auto &wallCollider = reinterpret_cast<Nibbler::BoxCollider &>(entity->getComponents("BoxCollider"));

            if (colliderComp.IsColliding(wallCollider)) {
                transformComp.setPosition(position);
                return false;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveNibbler, component not found" << std::endl;
            transformComp.setPosition(position);
            return false;
        }
    }
    transformComp.setPosition(position);
    return true;
}

bool Nibbler::MoveNibbler::IsDownValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position)
{
    auto &entities = entityManager.getEntities();
    auto &colliderComp = reinterpret_cast<Nibbler::NibblerHeadCollider &>(nibbler.getComponents("NibblerCollider"));
    auto &transformComp = reinterpret_cast<Nibbler::Transform &>(nibbler.getComponents("Transform"));

    auto tmpPos = position;
    tmpPos.y += CASE_SIZE - WALL_OFFSET_Y;
    if (tmpPos.y > 100 - CASE_SIZE)
        return false;
    transformComp.setPosition(tmpPos);
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("wall") == std::string::npos) {
            continue;
        }

        try {
            auto &wallCollider = reinterpret_cast<Nibbler::BoxCollider &>(entity->getComponents("BoxCollider"));

            if (colliderComp.IsColliding(wallCollider)) {
                transformComp.setPosition(position);
                return false;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveNibbler, component not found" << std::endl;
            transformComp.setPosition(position);
            return false;
        }
    }
    transformComp.setPosition(position);
    return true;
}

bool Nibbler::MoveNibbler::IsLeftValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position)
{
    auto &entities = entityManager.getEntities();
    auto &colliderComp = reinterpret_cast<Nibbler::NibblerHeadCollider &>(nibbler.getComponents("NibblerCollider"));
    auto &transformComp = reinterpret_cast<Nibbler::Transform &>(nibbler.getComponents("Transform"));

    auto tmpPos = position;
    tmpPos.x -= WALL_OFFSET_X;
    if (tmpPos.x < 0)
        return false;
    transformComp.setPosition(tmpPos);
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("wall") == std::string::npos) {
            continue;
        }

        try {
            auto &wallCollider = reinterpret_cast<Nibbler::BoxCollider &>(entity->getComponents("BoxCollider"));

            if (colliderComp.IsColliding(wallCollider)) {
                transformComp.setPosition(position);
                return false;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveNibbler, component not found" << std::endl;
            transformComp.setPosition(position);
            return false;
        }
    }
    transformComp.setPosition(position);
    return true;
}

bool Nibbler::MoveNibbler::IsRightValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position)
{
    auto &entities = entityManager.getEntities();
    auto &colliderComp = reinterpret_cast<Nibbler::NibblerHeadCollider &>(nibbler.getComponents("NibblerCollider"));
    auto &transformComp = reinterpret_cast<Nibbler::Transform &>(nibbler.getComponents("Transform"));

    auto tmpPos = position;
    tmpPos.x += CASE_SIZE - WALL_OFFSET_X;
    if (tmpPos.x > 100 - CASE_SIZE)
        return false;
    transformComp.setPosition(tmpPos);
    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("wall") == std::string::npos) {
            continue;
        }

        try {
            auto &wallCollider = reinterpret_cast<Nibbler::BoxCollider &>(entity->getComponents("BoxCollider"));

            if (colliderComp.IsColliding(wallCollider)) {
                transformComp.setPosition(position);
                return false;
            }
        } catch(const std::exception& e) {
            std::cerr << "moveNibbler, component not found" << std::endl;
            transformComp.setPosition(position);
            return false;
        }
    }
    transformComp.setPosition(position);
    return true;
}
