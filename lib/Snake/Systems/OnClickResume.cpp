// /*
// ** EPITECH PROJECT, 2023
// ** arcadEwE
// ** File description:
// ** OnClickResume
// */

// #include "OnClickResume.hpp"
// #include "Events.hpp"
// #include "IGameModule.hpp"
// #include "Sprite.hpp"

// namespace Snake {
//     void OnClickResume::run(float deltaTime,
//        Arcade::ECS::IEventManager &eventManager,
//        Arcade::ECS::IEntityManager &currentScene)
//     {
//         auto event = eventManager.isEventTriggered(MOUSE_CLICK);

//         if (!event.first) {
//             return;
//         }
//         auto &pos = eventManager.getMousePosition();
//         auto &entities = gameModule.getSceneManager().getCurrentScene()->getEntityManager().getEntities();

//         for (auto &entity : entities) {
//             auto idEntity = entity->getId();

//             if (idEntity.find("resume_button") == std::string::npos) {
//                 continue;
//             }
//             auto &spriteComp = entity->getComponents(Arcade::ECS::CompType::SPRITE).front();
//             auto &posEntity = reinterpret_cast<Arcade::Graph::Sprite *>(spriteComp.get())->getPos();
//             auto &sizeEntity = reinterpret_cast<Arcade::Graph::Sprite *>(spriteComp.get())->getSize();

//             if (pos.x >= posEntity.x && pos.x <= posEntity.x + sizeEntity.x && pos.y >= posEntity.y
//                 && pos.y <= posEntity.y + sizeEntity.y) {
//                 eventManager.addEvent("LOAD_SNAKE_GAME", spriteComp);
//             }
//         }
//     }
// } // namespace Snake
