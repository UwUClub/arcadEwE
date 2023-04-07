/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeTailManager
*/

#include "SnakeTailManager.hpp"
#include "Transform.hpp"
#include "IEntity.hpp"
#include "ObjectFactory.hpp"
#include "SnakeGameScene.hpp"
#include <regex>
#include <string>
#include <iostream>

namespace Snake {
    void SnakeTailManager::run(double deltaTime,
        Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
    {
        (void)deltaTime;

        auto eatFruitEvent = eventManager.isEventTriggered("EAT_FRUIT");
        if (eatFruitEvent.first) {
            auto entities = entityManager.getEntities();
            int lastNbr = 0;
            int currNbr = 0;

            for (auto &entity : entities) {
                auto id = entity->getId();
                std::regex regex("snake_body([0-9]+)");
                for(std::sregex_iterator i = std::sregex_iterator(id.begin(), id.end(), regex);
                        i != std::sregex_iterator(); ++i)
                {
                    std::smatch m = *i;
                    currNbr = std::stoi(m[1].str().c_str());
                }
                if (currNbr > lastNbr)
                    lastNbr = currNbr;
            }
            try {
                auto lastTail = entityManager.getEntitiesById("snake_body" + std::to_string(lastNbr));
                auto lastTailTransform = lastTail->getComponents("Transform");
                Arcade::Vector3f lastTailPos = reinterpret_cast<Snake::Transform &>(lastTailTransform).getPosition();
                Arcade::Vector3f pos = {lastTailPos.x + CASE_SIZE, lastTailPos.y + CASE_SIZE, lastTailPos.z};

                auto objectFactory = Snake::ObjectFactory();
                objectFactory.CreateSnakeBody(entityManager, pos, {0, 0, 0});
            } catch (std::exception &e) {
                std::cerr << "Error: last tail not found" << std::endl;
            }
        }
    }
}
