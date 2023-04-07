/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeTailManager
*/

#ifndef SNAKETAILMANAGER_HPP_
    #define SNAKETAILMANAGER_HPP_
    #include "ISystem.hpp"

namespace Snake {
    class SnakeTailManager : public Arcade::ECS::ISystem
    {
        public:
            SnakeTailManager() = default;
            ~SnakeTailManager() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) override;
        private:
            bool isTailValid(Arcade::ECS::IEntityManager &entityManager, std::string &id);
    };
}

#endif /* !SNAKETAILMANAGER_HPP_ */
