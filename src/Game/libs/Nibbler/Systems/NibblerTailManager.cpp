/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerTailManager
*/

#include "NibblerTailManager.hpp"
#include "Transform.hpp"
#include "IEntity.hpp"
#include "ObjectFactory.hpp"
#include "NibblerGameScene.hpp"
#include "Direction.hpp"
#include "ArcadeStruct.hpp"
#include "BoxCollider.hpp"
#include <regex>
#include <string>
#include <iostream>

namespace Nibbler {
    void NibblerTailManager::run(double deltaTime,
        Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
    {
        (void)deltaTime;

        auto eatFruitEvent = eventManager.isEventTriggered("FRUIT_EATEN");
        if (eatFruitEvent.first) {
            auto entities = entityManager.getEntities();
            int nibblerBodyCount= 0;

            for (auto &entity : entities) {
                std::string id = entity->getId();
                if (id.find("nibbler_body_") != std::string::npos) {
                    nibblerBodyCount++;
                }
            }
            try {
                auto lastTail = entityManager.getEntitiesById("nibbler_body_" + std::to_string(nibblerBodyCount - 1));
                if (lastTail == nullptr)
                    return;
                auto lastTailTransform = reinterpret_cast<Nibbler::Transform &>(lastTail->getComponents("Transform"));
                auto lastTailPos = lastTailTransform.getPosition();
                auto lastTailDirection = reinterpret_cast<Nibbler::Direction &>(lastTail->getComponents("Direction"));
                auto direction = lastTailDirection.getDirection();
                Arcade::Vector3f pos = lastTailPos;
                switch (direction) {
                    case Nibbler::Direction::UP:
                        pos.y += CASE_SIZE;
                        break;
                    case Nibbler::Direction::DOWN:
                        pos.y -= CASE_SIZE;
                        break;
                    case Nibbler::Direction::LEFT:
                        pos.x += CASE_SIZE;
                        break;
                    case Nibbler::Direction::RIGHT:
                        pos.x -= CASE_SIZE;
                        break;
                }
                auto objectFactory = Nibbler::ObjectFactory();
                objectFactory.CreateNibblerBody(entityManager, pos, {0, 0, 0});
                std::string id = "nibbler_body_" + std::to_string(nibblerBodyCount);
                if (!isTailValid(entityManager, id)) {
                    eventManager.addEvent("GAME_OVER");
                }
            } catch (std::exception &e) {
                std::cerr << "Error: last tail not found" << std::endl;
            }
        }
    }

    bool NibblerTailManager::isTailValid(Arcade::ECS::IEntityManager &entityManager, std::string &id) {
        auto entities = *entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::COLLIDER);
        auto tail = entityManager.getEntitiesById(id);
        if (tail == nullptr)
            return false;
        auto tailCollider = reinterpret_cast<BoxCollider &>(tail->getComponents("BoxCollider"));

        for (auto entity : entities) {
            if (entity == tail)
                continue;
            auto otherColliders = entity->getComponents(Arcade::ECS::CompType::COLLIDER);
            if (otherColliders.size() == 0 || !otherColliders[0])
                continue;
            auto &otherCollider = dynamic_cast<BoxCollider &>(*otherColliders[0]);
            if (!otherCollider.isEnabled)
                continue;
            if (tailCollider.IsColliding(otherCollider)) {
                return false;
            }
        }
        auto transformComp = reinterpret_cast<Transform &>(tail->getComponents("Transform"));
        auto pos = transformComp.getPosition();
        if (pos.x < 0 || pos.x > 100 - 1|| pos.y < 0 || pos.y > 100 - 1) {
            return false;
        }
        return true;
    }
}
