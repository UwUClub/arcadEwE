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

    /**
     * @brief Find all the libraries in the library folder and return information about them
     * @note This class is all static
     */
    class LibraryFinder
    {
        public:
        LibraryFinder() = delete;
        ~LibraryFinder() = delete;

        /**
         * @brief Get all the libraries in the library folder
         * @return A vector of pair containing the library type and the path to the library
         */
        static libList getLibraries();
        /**
         * @brief Get the library type from the path
         * @param path The path to the library
         * @return A pair containing the library type and the path to the library
         */
        static libInfo getLibType(const std::string &path);
        /**
         * @brief Load a library from the path
         * @param path The path to the library
         * @return A pointer to the library
         */
        static void *loadLibrary(const std::string &path);

        private:
        /**
         * @brief Exception class for the LibraryFinder
         */
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
