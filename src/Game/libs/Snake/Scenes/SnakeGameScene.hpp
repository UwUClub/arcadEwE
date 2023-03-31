/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameScene
*/

#ifndef SNAKEGAMESCENE_HPP_
    #define SNAKEGAMESCENE_HPP_
    #include "SnakeScene.hpp"
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080
    #define CASE_SIZE 120
    #define MAX_CASE_X SCREEN_WIDTH / CASE_SIZE
    #define MAX_CASE_Y SCREEN_HEIGHT / CASE_SIZE

namespace Snake {
    class SnakeGameScene : public SnakeScene
    {
        public:
            SnakeGameScene();
            ~SnakeGameScene() override = default;

            bool init() override;
    };
}

#endif /* !SNAKEGAMESCENE_HPP_ */
