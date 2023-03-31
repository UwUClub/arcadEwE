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

        if (posA.x + boxA.x / 2 < posB.x - boxB.x / 2)
            return false;
        if (posA.x - boxA.x / 2 > posB.x + boxB.x / 2)
            return false;
        if (posA.y + boxA.y / 2 < posB.y - boxB.y / 2)
            return false;
        if (posA.y - boxA.y / 2 > posB.y + boxB.y / 2)
            return false;
        if (posA.z + boxA.z / 2 < posB.z - boxB.z / 2)
            return false;
        if (posA.z - boxA.z / 2 > posB.z + boxB.z / 2)
            return false;
        return true;
    }

    void BoxCollider::setBox(Arcade::Vector3f box)
    {
        this->box = box;
    }

    Arcade::Vector3f BoxCollider::getBox() const
    {
        return this->box;
    }

    void BoxCollider::OnCollisionEnter(const Arcade::ECS::Entity &entity)
    {
        if (std::find(_collidingEntities.begin(), _collidingEntities.end(), &entity) == _collidingEntities.end())
            _collidingEntities.push_back(const_cast<Arcade::ECS::Entity *>(&entity));
        else
            OnCollisionStay(entity);
    }

    void BoxCollider::OnCollisionStay(const Arcade::ECS::Entity &entity)
    {
        (void)entity;
    }

    void BoxCollider::OnCollisionExit(const Arcade::ECS::Entity &entity)
    {
        auto it = std::find(_collidingEntities.begin(), _collidingEntities.end(), &entity);
        if (it != _collidingEntities.end())
            _collidingEntities.erase(it);
    }
}
