/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerTailManager
*/

#ifndef SNAKETAILMANAGER_HPP_
    #define SNAKETAILMANAGER_HPP_
    #include "ISystem.hpp"

namespace Nibbler {
    class NibblerTailManager : public Arcade::ECS::ISystem
    {
        public:
            NibblerTailManager() = default;
            ~NibblerTailManager() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) override;
        private:
            bool isTailValid(Arcade::ECS::IEntityManager &entityManager, std::string &id);
    };
}

#endif /* !SNAKETAILMANAGER_HPP_ */
