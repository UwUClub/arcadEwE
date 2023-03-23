//
// Created by patatofour on 23/03/23.
//

#ifndef ARCADE_ONCLICKGAMELIB_HPP
#define ARCADE_ONCLICKGAMELIB_HPP

#include "ISystem.hpp"

namespace Arcade::Core
{
    class OnClickGameLib : public ECS::ISystem
    {
        public:
        OnClickGameLib() = default;
        ~OnClickGameLib() override = default;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
    };
} // namespace Arcade::Core

#endif // ARCADE_ONCLICKGAMELIB_HPP
