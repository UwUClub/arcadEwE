//
// Created by patatofour on 28/03/23.
//

#ifndef SNAKE_MENUKEYBOARDHANDLER_HPP
#define SNAKE_MENUKEYBOARDHANDLER_HPP

#include "Events.hpp"
#include "ISystem.hpp"

namespace Snake
{
    class MenuKeyboardHandler final : public Arcade::ECS::ISystem
    {
        public:
        MenuKeyboardHandler();
        ~MenuKeyboardHandler() final = default;

        void run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) final;

        private:
            std::shared_ptr<Arcade::ECS::IEntity> getCurrentlyHoveredEntity(
            Arcade::ECS::IEntityManager &currentEntityManager);
    };
} // namespace Snake

#endif // SNAKE_MENUKEYBOARDHANDLER_HPP
