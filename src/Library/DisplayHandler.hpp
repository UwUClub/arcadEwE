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
    class DisplayHandler
    {
        public:
        explicit DisplayHandler(const std::string &path);

        ~DisplayHandler();

        Graph::IDisplayModule &operator*() const noexcept { return *_lib; }

        Graph::IDisplayModule *operator->() const noexcept { return _lib.get(); }

        private:
        void *_handle;
        std::unique_ptr<Graph::IDisplayModule> _lib;

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
