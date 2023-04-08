/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerHeadCollider
*/

#ifndef SNAKEHEADCOLLIDER_HPP_
    #define SNAKEHEADCOLLIDER_HPP_
    #include "BoxCollider.hpp"

namespace Nibbler {
    struct NibblerHeadCollider final : public BoxCollider {
        public:
            NibblerHeadCollider(const std::string &id, Arcade::Vector3f box, Transform &transform);
            ~NibblerHeadCollider() final = default;

            void OnCollisionEnter(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager) final;
            void OnCollisionStay(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager) final;
            void OnCollisionExit(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager) final;
    };
}

#endif /* !SNAKEHEADCOLLIDER_HPP_ */
