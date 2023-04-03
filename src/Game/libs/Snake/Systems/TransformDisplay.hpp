/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** TransformDisplay
*/

#ifndef TRANSFORMDISPLAY_HPP_
    #define TRANSFORMDISPLAY_HPP_
    #include "ISystem.hpp"

namespace Snake
{
    class TransformDisplay : public Arcade::ECS::ISystem
    {
        public:
            TransformDisplay() = default;
            ~TransformDisplay() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) override;
    };
}

#endif /* !TRANSFORMDISPLAY_HPP_ */
