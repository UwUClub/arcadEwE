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
#include "ISystemManager.hpp"
#include "Api.hpp"
#include "LibraryFinder.hpp"

namespace Arcade::Core
{
    class DisplayHandler
    {
        public:
        explicit DisplayHandler(const std::string &path);

        ~DisplayHandler();

        IDisplayModule &operator*() const noexcept { return *_lib; }

        IDisplayModule *operator->() const noexcept { return _lib; }

        private:
        void *_handle;
        IDisplayModule *_lib;

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
