/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** OnClickResume
*/

#ifndef ARCADE_ONCLICKRESUME_HPP
    #define ARCADE_ONCLICKRESUME_HPP

    #include "ISystem.hpp"

namespace Snake
{
    class OnClickResume : public Arcade::ECS::ISystem
    {
        public:
        OnClickResume() = default;
        ~OnClickResume() override = default;

        void run(float deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) override;
    };
} // namespace Snake

#endif // ARCADE_ONCLICKRESUME_HPP
