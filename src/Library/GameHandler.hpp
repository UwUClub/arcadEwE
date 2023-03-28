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
    class GameHandler
    {
        public:
        explicit GameHandler(const std::string &path);

        ~GameHandler();

        Game::IGameModule &operator*() const noexcept { return *_lib; }

        Game::IGameModule *operator->() const noexcept { return _lib.get(); }

        private:
        void *_handle;
        std::unique_ptr<Game::IGameModule> _lib;

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
#endif // ARCADE_GAMEHANDLER_HPP
