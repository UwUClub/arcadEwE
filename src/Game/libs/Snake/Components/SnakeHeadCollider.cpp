/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeHeadCollider
*/

#include "SnakeHeadCollider.hpp"
#include <iostream>

namespace Snake {
    SnakeHeadCollider::SnakeHeadCollider(const std::string &id, Arcade::Vector3f box, Transform &transform) :
        BoxCollider(id, box, transform)
    {
    }

    void SnakeHeadCollider::OnCollisionEnter(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        if (entity.getId() == "snake_body") {
            std::cout << "Game Over" << std::endl;
            eventManager.addEvent("GAME_OVER");
        }
        if (entity.getId() == "fruit") {
            std::cout << "Fruit" << std::endl;
            eventManager.addEvent("FRUIT_EATEN");
        }
        std::cout << "Collision" << std::endl;
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
