//
// Created by patatofour on 23/03/23.
//

#ifndef ARCADE_ONCLICKGRAPHLIB_HPP
#define ARCADE_ONCLICKGRAPHLIB_HPP

#include "ISystem.hpp"

namespace Arcade::Core
{
    class OnClickGraphLib : public ECS::ISystem
    {
        public:
        OnClickGraphLib() = default;
        ~OnClickGraphLib() override = default;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
    };
} // namespace Arcade::Core

#endif // ARCADE_ONCLICKGRAPHLIB_HPP
