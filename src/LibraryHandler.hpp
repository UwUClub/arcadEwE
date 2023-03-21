//
// Created by patatofour on 16/03/23.
//

#ifndef ARCADE_LIBRARYHANDLER_HPP
#define ARCADE_LIBRARYHANDLER_HPP

#include <string>
#include <memory>
#include <utility>
#include "ISystemManager.hpp"
#include "Api.hpp"

namespace Arcade::Core
{
    using libInfo = std::pair<LibType, std::string>;
    using libList = std::vector<libInfo>;

    class LibraryHandler
    {
        public:
            static void loadGameLibrary(const std::string &path);
            static void loadDisplayLibrary(const std::string &path);
            static void *loadLibrary(const std::string &path);
            static libList &getLibraries();
            [[nodiscard]] static libInfo getLibType(const std::string &path);

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
