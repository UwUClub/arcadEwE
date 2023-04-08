/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerTailManager
*/

#ifndef NIBBLERTAILMANAGER_HPP_
    #define NIBBLERTAILMANAGER_HPP_
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

#endif /* !NIBBLERTAILMANAGER_HPP_ */
