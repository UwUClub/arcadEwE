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
#include "Transform.hpp"
#include "BoxCollider.hpp"
#include "IEntity.hpp"
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
        auto &fruit = objectFactory.CreateFruit(entityManager, position);
        srand(time(0));
        std::vector<Arcade::Vector3f> positions;
        auto transforms = fruit.getComponents(Arcade::ECS::CompType::TRANSFORM);

        for (float x = 0; x < MAX_CASE_X; x++) {
            for (float y = 0; y < MAX_CASE_Y; y++) {

                for (auto &transform : transforms) {
                    auto &transformRef = dynamic_cast<Snake::Transform &>(*transform);
                    transformRef.setPosition({x * CASE_SIZE, y * CASE_SIZE, 0});
                    if (isFruitColliding(entityManager) == false)
                        positions.push_back({x * CASE_SIZE, y * CASE_SIZE, 0});
                }
            }
        }
        if (positions.size() > 0) {
            int random = rand() % positions.size();
            for (auto &transform : transforms) {
                auto &transformRef = dynamic_cast<Snake::Transform &>(*transform);
                transformRef.setPosition(positions[random]);
            }
            return true;
        }
        return false;
    }

    bool FruitSpawner::isFruitColliding(Arcade::ECS::IEntityManager &entityManager) {
        auto entities = *entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::COLLIDER);
        auto fruit = entityManager.getEntitiesById("fruit");

        for (auto entity : entities) {
            auto colliders = entity->getComponents(Arcade::ECS::CompType::COLLIDER);
            if (colliders.size() == 0 || !colliders[0])
                continue;
            auto &collider = dynamic_cast<BoxCollider &>(*colliders[0]);
            if (!collider.isEnabled)
                continue;
            for (auto &other : entities) {
                if (entity == other)
                    continue;
                auto otherColliders = other->getComponents(Arcade::ECS::CompType::COLLIDER);
                if (otherColliders.size() == 0 || !otherColliders[0])
                    continue;
                auto &otherCollider = dynamic_cast<BoxCollider &>(*otherColliders[0]);
                if (!otherCollider.isEnabled)
                    continue;
                if (collider.IsColliding(otherCollider)) {
                    return true;
                }
            }
        }
        return false;
    }
}
