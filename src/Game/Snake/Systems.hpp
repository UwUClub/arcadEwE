/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Systems
*/

#ifndef SYSTEMS_HPP_
    #define SYSTEMS_HPP_
    #include "ISystem.hpp"

namespace Snake {
    class MovementSystem : public Arcade::ECS::ISystem {
        public:
            MovementSystem();
            ~MovementSystem();

            void run(std::size_t deltaTime,
                Arcade::ECS::IEventManager &,
                Arcade::Core::IDisplayModule &displayModule,
                Arcade::Core::IGameModule &gameModule) final;

        protected:
        private:
    };
}

#endif /* !SYSTEMS_HPP_ */
