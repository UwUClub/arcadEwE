/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerHeadCollider
*/

#include "Direction.hpp"
#include "Events.hpp"
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
        if (entity.getId() == "horizontal_wall") {
            eventManager.addEvent("KEY_RIGHT_PRESSED");
        }
        if (entity.getId() == "vertical_wall") {
            eventManager.addEvent("KEY_DOWN_PRESSED");
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
