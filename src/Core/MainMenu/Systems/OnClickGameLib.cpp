//
// Created by patatofour on 23/03/23.
//

#include "OnClickGameLib.hpp"
#include "Events.hpp"
#include "IGameModule.hpp"
#include "Sprite.hpp"

void Arcade::Core::OnClickGameLib::run(std::size_t deltaTime,
    Arcade::ECS::IEventManager &eventManager, Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    auto event = eventManager.isEventTriggered(MOUSE_CLICK);

    if (!event.first) {
        return;
    }
    auto &pos = eventManager.getMousePosition();
    auto &entities
        = gameModule.getSceneManager().getCurrentScene()->getEntityManager().getEntities();

    for (auto &entity : entities) {
        auto idEntity = entity->getId();

        if (idEntity.find("game_button") == std::string::npos) {
            continue;
        }
        auto &spriteComp = entity->getComponents(ECS::CompType::SPRITE).front();
        auto &posEntity = reinterpret_cast<Arcade::Graph::Sprite *>(spriteComp.get())->getPos();
        auto &sizeEntity = reinterpret_cast<Arcade::Graph::Sprite *>(spriteComp.get())->getSize();

        if (pos.x >= posEntity.x && pos.x <= posEntity.x + sizeEntity.x && pos.y >= posEntity.y
            && pos.y <= posEntity.y + sizeEntity.y) {
            eventManager.addEvent(CHANGE_GAME, spriteComp);
        }
    }
}
