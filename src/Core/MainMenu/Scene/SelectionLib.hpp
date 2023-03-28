//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_SELECTIONLIB_HPP
#define ARCADE_SELECTIONLIB_HPP

#include "MainMenuScene.hpp"

#define BASE_X        20
#define OFFSET_Y_TEXT 50
#define OFFSET_X_TEXT 180

namespace Arcade::Game
{
    class SelectionLib : public MainMenuScene
    {
        public:
        SelectionLib();
        ~SelectionLib() override = default;

        bool init() override;
    };
} // namespace Arcade::Game

#endif // ARCADE_SELECTIONLIB_HPP
