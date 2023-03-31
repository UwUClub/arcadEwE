//
// Created by patatofour on 28/03/23.
//

#ifndef SNAKE_ISHOVERING_HPP
    #define SNAKE_ISHOVERING_HPP
    #include "ISystem.hpp"

namespace Snake
{
    class IsHovering : public Arcade::ECS::ISystem
    {
        public:
        IsHovering();
        ~IsHovering() override = default;

        void run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) override;
    };
} // namespace Snake

#endif // SNAKE_ISHOVERING_HPP
