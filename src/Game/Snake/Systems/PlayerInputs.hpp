/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** PlayerInputs
*/

#ifndef PLAYERINPUTS_HPP_
    #define PLAYERINPUTS_HPP_

    #include "ISystem.hpp"

namespace Snake
{
    class PlayerInputs : public Arcade::ECS::ISystem
    {
        public:
        PlayerInputs() = default;
        ~PlayerInputs() override = default;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
    };
} // namespace Arcade::Core

#endif /* !PLAYERINPUTS_HPP_ */
