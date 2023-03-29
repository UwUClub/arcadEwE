//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_SAVEREADER_HPP
#define ARCADE_SAVEREADER_HPP

#include "MainMenuScene.hpp"

#define BASE_X_SAVE 60

namespace Arcade::Game
{
    class SaveReader : public MainMenuScene
    {
        public:
        SaveReader();
        ~SaveReader() override = default;

        bool init() final;

        private:
        class SaveReaderException : public std::exception
        {
            public:
            SaveReaderException(const std::string &message)
                : _message(message)
            {
            }

            ~SaveReaderException() override = default;

            const char *what() const noexcept override
            {
                return _message.c_str();
            }

            private:
            std::string _message;
        };

        void loadSave();
        std::string _saveContent;
    };
} // namespace Arcade::Game

#endif // ARCADE_SAVEREADER_HPP
