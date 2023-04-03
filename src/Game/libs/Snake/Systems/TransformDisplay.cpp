/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** TransformDisplay
*/

#include "TransformDisplay.hpp"
#include "Transform.hpp"
#include "Sprite.hpp"
#include <algorithm>
#include <vector>

void Snake::TransformDisplay::run(double deltaTime,
    Arcade::ECS::IEventManager &eventManager,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto entitiesPtr = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::TRANSFORM);
    if (!entitiesPtr)
        return;
    auto entities = *entitiesPtr;

    (void)(eventManager);
    (void)(deltaTime);
    for (auto &entity : entities) {
        auto &sprites = entity->getComponents(Arcade::ECS::CompType::SPRITE);
        auto transforms = entity->getComponents(Arcade::ECS::CompType::TRANSFORM);
        auto &transform = dynamic_cast<Snake::Transform &>(*transforms[0]);

        for (auto &iSprite : sprites) {
            auto &sprite = dynamic_cast<Snake::Sprite &>(*iSprite);

            sprite.pos.x = transform.position.x;
            sprite.pos.y = transform.position.y;
            sprite.pos.z = transform.position.z;
        }
    }
}
