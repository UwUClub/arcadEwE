/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ColliderManager
*/

#include "ColliderManager.hpp"
#include "Events.hpp"
#include "Transform.hpp"
#include "BoxCollider.hpp"
#include <algorithm>
#include <vector>

void Nibbler::ColliderManager::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto entitiesPtr = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::COLLIDER);
    if (!entitiesPtr)
        return;
    auto entities = *entitiesPtr;

    (void)(eventManager);
    (void)(deltaTime);
    for (auto &entity : entities) {
        auto &colliders = entity->getComponents(Arcade::ECS::CompType::COLLIDER);

        for (auto &collider : colliders) {
            auto &boxCollider = dynamic_cast<BoxCollider &>(*collider);
            if (!boxCollider.isEnabled)
                continue;
            for (auto &otherEntity : entities) {
                if (entity->getId() == otherEntity->getId())
                    continue;
                auto &otherColliders = otherEntity->getComponents(Arcade::ECS::CompType::COLLIDER);
                for (auto &otherCollider : otherColliders) {
                    auto &otherBoxCollider = dynamic_cast<BoxCollider &>(*otherCollider);
                    if (!otherBoxCollider.isEnabled)
                        continue;
                    if (boxCollider.IsColliding(otherBoxCollider)) {
                        if (std::find(boxCollider._collidingEntities.begin(), boxCollider._collidingEntities.end(), otherEntity->getId()) == boxCollider._collidingEntities.end()) {
                            boxCollider._collidingEntities.emplace_back(otherEntity->getId());
                            boxCollider.OnCollisionEnter(*otherEntity, eventManager);
                        } else {
                            boxCollider.OnCollisionStay(*otherEntity, eventManager);
                        }
                    } else {
                        auto it = std::find(boxCollider._collidingEntities.begin(), boxCollider._collidingEntities.end(), otherEntity->getId());
                        if (it != boxCollider._collidingEntities.end()) {
                            boxCollider._collidingEntities.erase(it);
                            boxCollider.OnCollisionExit(*otherEntity, eventManager);
                        }
                    }
                }
            }
        }
    }
}
