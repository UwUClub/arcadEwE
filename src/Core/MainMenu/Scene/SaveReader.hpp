//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_SAVEREADER_HPP
#define ARCADE_SAVEREADER_HPP

#include "AScene.hpp"

#define BASE_X_SAVE 60

namespace Arcade::Game
{
    class SaveReader : public AScene
    {
        public:
        SaveReader();
        ~SaveReader() override = default;

        bool init() final;

        private:
        void loadSave();
        std::string _saveContent;
    };
} // namespace Arcade::Game

#endif // ARCADE_SAVEREADER_HPP
