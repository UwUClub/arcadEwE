//
// Created by patatofour on 28/03/23.
//

#ifndef NIBBLER_MENUKEYBOARDHANDLER_HPP
#define NIBBLER_MENUKEYBOARDHANDLER_HPP

#include "Events.hpp"
#include "ISystem.hpp"

namespace Nibbler
{
    class MenuKeyboardHandler final : public Arcade::ECS::ISystem
    {
        public:
        MenuKeyboardHandler();
        ~MenuKeyboardHandler() final = default;

        void run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) final;

        private:
            std::shared_ptr<Arcade::ECS::IEntity> getCurrentlyHoveredEntity(
            Arcade::ECS::IEntityManager &currentEntityManager);
    };
} // namespace Nibbler

#endif // NIBBLER_MENUKEYBOARDHANDLER_HPP
