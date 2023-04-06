/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveTail
*/

#ifndef MOVETAIL_HPP_
    #define MOVETAIL_HPP_
    #include "ISystem.hpp"

namespace Snake
{
    class MoveTail : public Arcade::ECS::ISystem
    {
        public:
            MoveTail() = default;
            ~MoveTail() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) override;
    };
}

#endif /* !MOVETAIL_HPP_ */
