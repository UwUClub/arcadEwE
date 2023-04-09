/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveNibbler
*/

#ifndef MOVENIBBLER_HPP_
    #define MOVENIBBLER_HPP_
    #include "ISystem.hpp"

namespace Nibbler
{
    class MoveNibbler : public Arcade::ECS::ISystem
    {
        public:
            MoveNibbler() = default;
            ~MoveNibbler() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) override;
        private:
            bool IsUpValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position);
            bool IsDownValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position);
            bool IsLeftValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position);
            bool IsRightValid(Arcade::ECS::IEntityManager &entityManager, Arcade::ECS::IEntity &nibbler, Arcade::Vector3f position);
    };
}

#endif /* !MOVENIBBLER_HPP_ */
