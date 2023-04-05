/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeHeadCollider
*/

#ifndef SNAKEHEADCOLLIDER_HPP_
    #define SNAKEHEADCOLLIDER_HPP_
    #include "BoxCollider.hpp"

namespace Snake {
    struct SnakeHeadCollider final : public BoxCollider {
        public:
            SnakeHeadCollider(const std::string &id, Arcade::Vector3f box, Transform &transform);
            ~SnakeHeadCollider() final = default;

            void OnCollisionEnter(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager) final;
            void OnCollisionStay(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager) final;
            void OnCollisionExit(const Arcade::ECS::IEntity &entity, Arcade::ECS::IEventManager &eventManager) final;
    };
}

#endif /* !SNAKEHEADCOLLIDER_HPP_ */
