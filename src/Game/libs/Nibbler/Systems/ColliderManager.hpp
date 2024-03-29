/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ColliderManager
*/

#ifndef COLLIDERMANAGER_HPP_
    #define COLLIDERMANAGER_HPP_
    #include "ISystem.hpp"

namespace Nibbler
{
    class ColliderManager : public Arcade::ECS::ISystem
    {
        public:
            ColliderManager() = default;
            ~ColliderManager() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) override;
    };
}

#endif /* !COLLIDERMANAGER_HPP_ */
