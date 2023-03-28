//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_ISHOVERING_HPP
#define ARCADE_ISHOVERING_HPP

#include "ISystem.hpp"

namespace Arcade::Game
{
    class IsHovering : public Arcade::ECS::ISystem
    {
        public:
        IsHovering();
        ~IsHovering() override = default;

        void run(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) override;
    };
} // namespace Arcade::Game

#endif // ARCADE_ISHOVERING_HPP
