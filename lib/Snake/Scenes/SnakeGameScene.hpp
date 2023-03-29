/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameScene
*/

#ifndef SNAKEGAMESCENE_HPP_
    #define SNAKEGAMESCENE_HPP_
    #include "SnakeScene.hpp"
    #define SNAKE_PATH "assets/images/SnakeSpriteSheet.png"

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
