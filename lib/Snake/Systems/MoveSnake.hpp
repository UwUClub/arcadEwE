/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** MoveSnake
*/

#ifndef MOVESNAKE_HPP_
    #define MOVESNAKE_HPP_
    #include "ISystem.hpp"

namespace Snake
{
    class MoveSnake : public Arcade::ECS::ISystem
    {
        public:
            MoveSnake() = default;
            ~MoveSnake() override = default;

            void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) override;
    };
}

#endif /* !MOVESNAKE_HPP_ */
