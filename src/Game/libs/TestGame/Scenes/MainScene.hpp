//
// Created by valegox on 29/03/23.
//

#pragma once

#include "AScene.hpp"

namespace Arcade::Game
{
    class MainScene : public AScene
    {
        public:
        MainScene();
        virtual ~MainScene() = default;

        private:
        bool init() final;

    };
} // namespace Arcade::Game
