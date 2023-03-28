//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include "ICore.hpp"
#include "DisplayHandler.hpp"
#include "GameHandler.hpp"
#include "LibraryFinder.hpp"

#define FONT_PATH "assets/fonts/Roboto-Regular.ttf"

namespace Arcade::Core
{
    class Core : public ICore
    {
        public:
        Core(const std::string &pathDisplay);
        ~Core() override = default;

        void update() override;

        private:
        void loadGameModule(const std::string &path);
        void loadGameModule();
        void loadDisplayModule(const std::string &path);
        void loadDisplayModule();
        void handleCoreEvents();

        std::unique_ptr<GameHandler> _gameModule;
        std::string _currentGameModule;
        std::unique_ptr<Game::IGameModule> _mainMenu;
        std::unique_ptr<DisplayHandler> _displayModule;
        std::string _currentDisplayModule;
        std::unique_ptr<ECS::IEventManager> _eventManager;
    };
} // namespace Arcade::Core

#endif // ARCADE_CORE_HPP
