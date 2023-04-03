//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_KEYBOARDHANDLER_HPP
#define ARCADE_KEYBOARDHANDLER_HPP

#include "Events.hpp"
#include "ISystem.hpp"

namespace Arcade::Game
{
    class KeyboardHandler final : public Arcade::ECS::ISystem
    {
        public:
        KeyboardHandler();
        ~KeyboardHandler() final = default;

        void run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) final;

        private:
        std::shared_ptr<ECS::IEntity> getCurrentlyHoveredEntity(
            Arcade::ECS::IEntityManager &currentEntityManager);
    };
} // namespace Arcade::Game

#endif // ARCADE_KEYBOARDHANDLER_HPP
