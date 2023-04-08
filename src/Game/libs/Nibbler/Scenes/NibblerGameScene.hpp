/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameScene
*/

#ifndef SNAKEGAMESCENE_HPP_
    #define SNAKEGAMESCENE_HPP_
    #include "NibblerScene.hpp"
    #define SCREEN_WIDTH 100
    #define SCREEN_HEIGHT 100
    #define CASE_SIZE 10
    #define MAX_CASE_X SCREEN_WIDTH / CASE_SIZE
    #define MAX_CASE_Y SCREEN_HEIGHT / CASE_SIZE

namespace Nibbler {
    class NibblerGameScene : public NibblerScene
    {
        public:
            NibblerGameScene();
            ~NibblerGameScene() override = default;

            bool init() override;
    };
}

#endif /* !SNAKEGAMESCENE_HPP_ */
