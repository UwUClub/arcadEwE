/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** BoxCollider
*/

#include "BoxCollider.hpp"
#include <algorithm>

namespace Snake {
    BoxCollider::BoxCollider(const std::string &id, Arcade::Vector3f box, Transform &transform) :
        Arcade::ECS::Component(Arcade::ECS::CompType::COLLIDER, id),
        box(box),
        transform(transform)
    {
    }

    bool BoxCollider::IsColliding(const BoxCollider &other) const
    {
        Arcade::Vector3f posA = transform.getPosition();
        Arcade::Vector3f posB = other.transform.getPosition();
        Arcade::Vector3f boxA = box;
        Arcade::Vector3f boxB = other.box;

        if (posA.x < posB.x + boxB.x &&
            posA.x + boxA.x > posB.x &&
            posA.y < posB.y + boxB.y &&
            posA.y + boxA.y > posB.y) {
            return true;
        }
        return false;
    }

    void BoxCollider::setBox(Arcade::Vector3f box)
    {
        this->box = box;
    }

    Arcade::Vector3f BoxCollider::getBox() const
    {
        return this->box;
    }

    void BoxCollider::OnCollisionEnter(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }

    void BoxCollider::OnCollisionStay(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }

    void BoxCollider::OnCollisionExit(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }
}
