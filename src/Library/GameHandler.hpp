//
// Created by patatofour on 27/03/23.
//

#ifndef ARCADE_GAMEHANDLER_HPP
#define ARCADE_GAMEHANDLER_HPP

#include <string>
#include <memory>
#include <utility>
#include <dlfcn.h>
#include <iostream>
#include "LibraryFinder.hpp"
#include "IGameModule.hpp"

namespace Arcade::Core
{
    /**
     * @brief GameHandler class
     * @details This class is used to load a game module
     */
    class GameHandler
    {
        public:
        /**
         * @brief GameHandler constructor
         * @details This constructor is used to load a game module
         * @param path The path to the game library
         */
        explicit GameHandler(const std::string &path);

        /**
         * @brief GameHandler destructor
         * @details This destructor is used to unload the game module and close the library
         */
        ~GameHandler();

        /**
         * @brief Get the game module
         * @details Overload of the * operator
         * @return A reference to the game module
         */
        Game::IGameModule &operator*() const noexcept
        {
            return *_lib;
        }

        /**
         * @brief Get the game module
         * @details Overload of the -> operator
         * @return A pointer to the game module
         */
        Game::IGameModule *operator->() const noexcept
        {
            return _lib;
        }

        private:
        void *_handle;
        Game::IGameModule *_lib;
    };
} // namespace Arcade::Core
#endif // ARCADE_GAMEHANDLER_HPP
