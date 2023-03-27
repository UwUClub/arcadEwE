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
#include "DisplayHandler.hpp"
#include "GameHandler.hpp"
#include "LibraryFinder.hpp"

namespace Arcade::Core
{
    class Core : public ICore
    {
        public:
        Core();
        ~Core() override = default;

        void run();

        private:
        void loadGameModule(const std::string &path);
        void loadGameModule();
        void loadDisplayModule(const std::string &path);
        void loadDisplayModule();
        void handleCoreEvents();

        std::unique_ptr<GameHandler> _gameModule;
        std::string _currentGameModule;
        std::unique_ptr<DisplayHandler> _displayModule;
        std::string _currentDisplayModule;
        std::unique_ptr<ECS::IEventManager> _eventManager;
    };
} // namespace Arcade::Core

#endif // ARCADE_CORE_HPP
