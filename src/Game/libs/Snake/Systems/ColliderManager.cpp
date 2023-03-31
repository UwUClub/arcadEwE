/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ColliderManager
*/

#include "ColliderManager.hpp"
#include "Events.hpp"
#include "Transform.hpp"

void Snake::ColliderManager::run(float deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto &entities = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::COLLIDER);

    (void)(deltaTime);
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
                collider.OnCollisionEnter(*other);
                otherCollider.OnCollisionEnter(*entity);
            } else {
                collider.OnCollisionExit(*other);
                otherCollider.OnCollisionExit(*entity);
            }
        }
    }
}
