//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include "ICore.hpp"
#include "DisplayHandler.hpp"
#include "GameHandler.hpp"
#include "LibraryFinder.hpp"
#include "Clock.hpp"

#define FONT_PATH "assets/fonts/arcade.ttf"
#define MENU_PATH "./lib/libarcade_mainMenu_game.so"

namespace Arcade::Core
{
    /**
     * @brief Core class of the Arcade
     */
    class Core : public ICore
    {
        public:
        /**
         * @brief Construct a new Core object
         *
         * @param pathDisplay Path to the display module
         */
        explicit Core(const std::string &pathDisplay);
        /**
         * @brief Destroy the Core object
         */
        ~Core() override = default;

        /**
         * @brief This function is the main loop of the Arcade
         * It will handle the events and update the display and the game
         */
        void update() override;

        private:
        /**
         * @brief This function is used to load the game module
         *
         * @param path Path to the game module
         */
        void loadGameModule(const std::string &path);
        /**
         * @brief This function is used to load the game module
         * It changes the game module to the next one in the list
         */
        void loadGameModule();
        /**
         * @brief This function is used to load the display module
         *
         * @param path Path to the display module
         */
        void loadDisplayModule(const std::string &path);
        /**
         * @brief This function is used to load the display module
         * It changes the display module to the next one in the list
         */
        void loadDisplayModule();
        /**
         * @brief This function is used to handle the events of the Arcade
         */
        void handleCoreEvents();

        std::unique_ptr<GameHandler> _gameModule;
        std::string _currentGameModule;
        std::unique_ptr<DisplayHandler> _displayModule;
        std::string _currentDisplayModule;
        std::unique_ptr<ECS::IEventManager> _eventManager;
        std::unique_ptr<Clock> _clock;
    };
} // namespace Arcade::Core

#endif // ARCADE_CORE_HPP
