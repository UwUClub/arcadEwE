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

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
    };
} // namespace Snake

#endif // ARCADE_ONCLICKRESUME_HPP
