//
// Created by patatofour on 16/03/23.
//

#ifndef ARCADE_LIBRARYHANDLER_HPP
#define ARCADE_LIBRARYHANDLER_HPP

#include <string>
#include <memory>
#include <utility>
#include "IGame.hpp"
#include "IGraph.hpp"

namespace Arcade::Core
{
    class LibraryHandler
    {
        public:
            static std::unique_ptr<Arcade::Game::IGame *> loadGameLibrary(const std::string &path);
            static std::unique_ptr<Arcade::Graph::IGraph *> loadGraphicLibrary(const std::string &path);

        private:
            static std::unique_ptr<void *> loadSymbol(void *handle, const std::string &symbol);

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
