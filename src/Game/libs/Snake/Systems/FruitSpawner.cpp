/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** FruitSpawner
*/

#include "FruitSpawner.hpp"
#include "Events.hpp"
#include "ObjectFactory.hpp"
#include "SnakeGameScene.hpp"
#include <cstdlib>
#include <time.h>
#include <vector>

namespace Snake {
    void FruitSpawner::run(float deltaTime,
        Arcade::ECS::IEventManager &eventManager,
        Arcade::ECS::IEntityManager &entityManager)
    {
        (void)(deltaTime);
        (void)(eventManager);
        if (entityManager.getEntitiesById("fruit") == nullptr)
            if (SpawnFruit(entityManager) == false)
                eventManager.addEvent("GAME_OVER");
    }

    bool FruitSpawner::SpawnFruit(Arcade::ECS::IEntityManager &entityManager)
    {
        Arcade::Vector3f position = {0, 0, 0};
        ObjectFactory objectFactory;
        auto fruit = objectFactory.CreateFruit(entityManager, position);
        srand(time(0));
        std::vector<Arcade::Vector3f> positions;

        for (int x = 0; x < MAX_CASE_X; x++) {
            for (int y = 0; y < MAX_CASE_Y; y++) {
                fruit.getComponents(Arcade::ECS::CompType::TRANSFORM).SetPosition = {x * CASE_SIZE, y * CASE_SIZE, 0};
                if (isFruitColliding(entityManager) == false)
                    positions.push_back(fruit.getComponent<Transform>(Arcade::ECS::CompType::TRANSFORM).GetPosition);
            }
        }
        if (positions.size() > 0) {
            int random = rand() % positions.size();
            fruit.getComponents(Arcade::ECS::CompType::TRANSFORM).SetPosition = positions[random];
            return true;
        }
        return false;
    }

    bool FruitSpawner::isFruitColliding(Arcade::ECS::IEntityManager &entityManager) {
        auto &entities = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::COLLIDER);
        auto &fruit = entityManager.getEntitiesById("fruit");

        for (auto &entity : entities) {
            auto &collider = entity->getComponent<BoxCollider>(Arcade::ECS::CompType::COLLIDER);
            if (!collider.isEnabled)
                continue;
            for (auto &other : entities) {
                if (entity == other)
                    continue;
                auto &otherCollider = other->getComponent<BoxCollider>(Arcade::ECS::CompType::COLLIDER);
                if (!otherCollider.isEnabled)
                    continue;
                if (collider.isColliding(otherCollider)) {
                    return true;
                }
            }
        }
        return false;
    }
}
