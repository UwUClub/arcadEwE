//
// Created by patatofour on 28/03/23.
//

#ifndef NIBBLER_ISHOVERING_HPP
    #define NIBBLER_ISHOVERING_HPP
    #include "ISystem.hpp"

namespace Nibbler
{
    class IsHovering : public Arcade::ECS::ISystem
    {
        public:
        IsHovering();
        ~IsHovering() override = default;

        void run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) override;
    };
} // namespace Nibbler

#endif // NIBBLER_ISHOVERING_HPP
