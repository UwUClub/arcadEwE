/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameManager
*/

#ifndef SNAKEGAMEMANAGER_HPP_
    #define SNAKEGAMEMANAGER_HPP_
    #include "ISystem.hpp"

namespace Nibbler
{
    class NibblerGameManager : public Arcade::ECS::ISystem
    {
        public:
            NibblerGameManager() = default;
            ~NibblerGameManager() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &currentScene) override;
    };
}

#endif /* !SNAKEGAMEMANAGER_HPP_ */
