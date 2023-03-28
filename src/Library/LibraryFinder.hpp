//
// Created by patatofour on 27/03/23.
//

#ifndef ARCADE_LIBRARYFINDER_HPP
#define ARCADE_LIBRARYFINDER_HPP

#include "Api.hpp"

namespace Arcade::Core
{
    using libInfo = std::pair<LibType, std::string>;
    using libList = std::vector<libInfo>;

    class LibraryFinder
    {
        public:
        LibraryFinder() = delete;
        ~LibraryFinder() = delete;

        static libList getLibraries();
        static libInfo getLibType(const std::string &path);
        static void *loadLibrary(const std::string &path);

        private:
        class LibraryFinderException : public std::exception
        {
            public:
            explicit LibraryFinderException(const std::string &message)
                : _message(message)
            {
            }

            ~LibraryFinderException() noexcept override = default;

            [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

            private:
            std::string _message;
        };
    };
} // namespace Arcade::Core
#endif // ARCADE_LIBRARYFINDER_HPP
