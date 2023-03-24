//
// Created by patatofour on 23/03/23.
//

#include "OnClickGameLib.hpp"
#include "Events.hpp"
#include "IGameModule.hpp"
#include "Text.hpp"
#include "TextHitbox.hpp"

void Arcade::Core::OnClickGameLib::run(std::size_t deltaTime,
    Arcade::ECS::IEventManager &eventManager, Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    auto event = eventManager.isEventTriggered(MOUSE_CLICK);

    if (!event.first) {
        return;
    }
    auto &mouse_pos = eventManager.getMousePosition();
    auto &entities
        = gameModule.getSceneManager().getCurrentScene()->getEntityManager().getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("button") == std::string::npos) {
            continue;
        }
        auto &textComp = entity->getComponents(ECS::CompType::TEXT).front();
        auto &hitboxComp = entity->getComponents(ECS::CompType::HITBOX_TEXT).front();
        auto &posEntity = reinterpret_cast<Graph::Text *>(textComp.get())->getPos();
        auto &sizeEntity = reinterpret_cast<Core::TextHitbox *>(hitboxComp.get())->getBox();

        if (mouse_pos.x >= posEntity.x && mouse_pos.x <= posEntity.x + sizeEntity.x
            && mouse_pos.y >= posEntity.y && mouse_pos.y <= posEntity.y + sizeEntity.y) {
            if (idEntity.find("graph_button_") != std::string::npos)
                eventManager.addEvent(CHANGE_GRAPHIC, spriteComp);
            else if (idEntity.find("game_button_") != std::string::npos)
                eventManager.addEvent(CHANGE_GAME, spriteComp);
        }
    }
}
