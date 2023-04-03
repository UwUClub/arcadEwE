/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameManager
*/

#ifndef SNAKEGAMEMANAGER_HPP_
    #define SNAKEGAMEMANAGER_HPP_
    #include "ISystem.hpp"

namespace Snake
{
    class SnakeGameManager : public Arcade::ECS::ISystem
    {
        public:
            SnakeGameManager() = default;
            ~SnakeGameManager() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) override;
    };
}

#endif /* !SNAKEGAMEMANAGER_HPP_ */
