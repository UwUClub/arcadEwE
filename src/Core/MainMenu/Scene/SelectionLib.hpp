//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_SELECTIONLIB_HPP
#define ARCADE_SELECTIONLIB_HPP

#include "AScene.hpp"

#define BASE_X_TEXT   60
#define OFFSET_Y_TEXT 10
#define OFFSET_X_TEXT 18

namespace Arcade::Game
{
    class SelectionLib : public AScene
    {
        public:
        SelectionLib();
        ~SelectionLib() override = default;

        bool init() final;
    };
} // namespace Arcade::Game

#endif // ARCADE_SELECTIONLIB_HPP
