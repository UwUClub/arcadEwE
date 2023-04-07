/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeHeadCollider
*/

#include "SnakeHeadCollider.hpp"

namespace Snake {
    SnakeHeadCollider::SnakeHeadCollider(const std::string &id, Arcade::Vector3f box, Transform &transform) :
        BoxCollider(id, box, transform)
    {
    }

    void SnakeHeadCollider::OnCollisionEnter(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        if (entity.getId().find("snake_body_") != std::string::npos) {
            eventManager.addEvent("GAME_OVER");
        }
        if (entity.getId() == "fruit") {
            eventManager.addEvent("FRUIT_EATEN");
        }
        (void)entity;
        (void)eventManager;
    }

    void SnakeHeadCollider::OnCollisionStay(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }

    void SnakeHeadCollider::OnCollisionExit(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }
}
