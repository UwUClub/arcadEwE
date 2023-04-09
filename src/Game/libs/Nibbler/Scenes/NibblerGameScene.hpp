/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameScene
*/

#ifndef NIBBLERGAMESCENE_HPP_
    #define NIBBLERGAMESCENE_HPP_
    #include "NibblerScene.hpp"
    #define SCREEN_WIDTH 100
    #define SCREEN_HEIGHT 100
    #define CASE_SIZE 10
    #define MAX_CASE_X (SCREEN_WIDTH / CASE_SIZE - 2)
    #define MAX_CASE_Y (SCREEN_HEIGHT / CASE_SIZE - 2)
    #define WALL_OFFSET_X 4
    #define WALL_OFFSET_Y 2

namespace Nibbler {
    class NibblerGameScene : public NibblerScene
    {
        public:
            NibblerGameScene();
            ~NibblerGameScene() override = default;

            bool init() override;
    };
}

#endif /* !NIBBLERGAMESCENE_HPP_ */
