//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include "ICore.hpp"
#include "IEventManager.hpp"
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"
#include "Api.hpp"

namespace Arcade::Core
{
    class Core : public ICore
    {
        public:
        Core();
        ~Core() override = default;

        void run();

        private:
        int handleCoreEvents();
        std::unique_ptr<IGameModule> _gameModule;
        std::unique_ptr<IDisplayModule> _displayModule;
        std::unique_ptr<ECS::IEventManager> _eventManager;
    };
} // namespace Arcade::Core

#endif // ARCADE_CORE_HPP
