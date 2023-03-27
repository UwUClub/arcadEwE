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
#include "ISystemManager.hpp"
#include "Api.hpp"
#include "LibraryFinder.hpp"

namespace Arcade::Core
{
    class GameHandler
    {
        public:
        explicit GameHandler(const std::string &path);

        ~GameHandler();

        IGameModule &operator*() const noexcept { return *_lib; }

        IGameModule *operator->() const noexcept { return _lib; }

        private:
        void *_handle;
        IGameModule *_lib;

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
