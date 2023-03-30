//
// Created by patatofour on 16/03/23.
//

#ifndef ARCADE_DISPLAYHANDLER_HPP
#define ARCADE_DISPLAYHANDLER_HPP

#include <string>
#include <memory>
#include <utility>
#include <dlfcn.h>
#include <iostream>
#include "LibraryFinder.hpp"
#include "IDisplayModule.hpp"

namespace Arcade::Core
{
    /**
     * @brief DisplayHandler class
     * @details This class is used to load a display module
     */
    class DisplayHandler
    {
        public:
        /**
         * @brief DisplayHandler constructor
         * @details This constructor is used to load a display module
         * @param path The path to the display library
         */
        explicit DisplayHandler(const std::string &path);

        /**
         * @brief DisplayHandler destructor
         * @details This destructor is used to unload the display module and close the library
         */
        ~DisplayHandler();

        /**
         * @brief Get the display module
         * @details Overload of the * operator
         * @return A reference to the display module
         */
        Graph::IDisplayModule &operator*() const noexcept { return *_lib; }

        /**
         * @brief Get the display module
         * @details Overload of the -> operator
         * @return A pointer to the display module
         */
        Graph::IDisplayModule *operator->() const noexcept { return _lib.get(); }

        private:
        void *_handle;
        std::unique_ptr<Graph::IDisplayModule> _lib;

        /**
         * @brief Exception class for the DisplayHandler
         */
        class LibraryHandlerException : public std::exception
        {
            public:
            explicit LibraryHandlerException(const std::string &message)
                : _message(message)
            {
            }

            ~LibraryHandlerException() noexcept override = default;

            [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

            private:
            std::string _message;
        };
    };
} // namespace Arcade::Core

#endif // ARCADE_DISPLAYHANDLER_HPP
