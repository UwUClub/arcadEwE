/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerHeadCollider
*/

#include "NibblerHeadCollider.hpp"

namespace Nibbler {
    NibblerHeadCollider::NibblerHeadCollider(const std::string &id, Arcade::Vector3f box, Transform &transform) :
        BoxCollider(id, box, transform)
    {
    }

    void NibblerHeadCollider::OnCollisionEnter(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        if (entity.getId().find("nibbler_body_") != std::string::npos) {
            eventManager.addEvent("GAME_OVER");
        }
        if (entity.getId() == "fruit") {
            eventManager.addEvent("FRUIT_EATEN");
        }
        (void)entity;
        (void)eventManager;
    }

    void NibblerHeadCollider::OnCollisionStay(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }

    void NibblerHeadCollider::OnCollisionExit(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager)
    {
        (void)entity;
        (void)eventManager;
    }
}
