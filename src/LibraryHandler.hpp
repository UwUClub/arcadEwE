//
// Created by patatofour on 16/03/23.
//

#ifndef ARCADE_LIBRARYHANDLER_HPP
#define ARCADE_LIBRARYHANDLER_HPP

#include <string>
#include <memory>
#include <utility>
#include "ISystemManager.hpp"

namespace Arcade::Core
{
    class LibraryHandler
    {
        public:
            static void loadLibrary(const std::string &path, std::unique_ptr<ECS::ISystemManager> &systemManager);

        private:
            class LibraryHandlerException : public std::exception
            {
                public:
                    explicit LibraryHandlerException(std::string message) : _message(std::move(message)) {}
                    ~LibraryHandlerException() noexcept override = default;
                    [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }
                private:
                    std::string _message;
            };
    };
}

#endif // ARCADE_LIBRARYHANDLER_HPP
