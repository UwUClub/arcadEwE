/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerHeadCollider
*/

#ifndef NIBBLERHEADCOLLIDER_HPP_
    #define NIBBLERHEADCOLLIDER_HPP_
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

#endif /* !NIBBLERHEADCOLLIDER_HPP_ */
