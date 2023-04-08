/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameManager
*/

#ifndef NIBBLERGAMEMANAGER_HPP_
    #define NIBBLERGAMEMANAGER_HPP_
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

#endif /* !NIBBLERGAMEMANAGER_HPP_ */
