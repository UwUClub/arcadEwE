/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeMenuScene
*/

#ifndef SNAKEMENUSCENE_HPP_
    #define SNAKEMENUSCENE_HPP_
    #include "SnakeScene.hpp"
    #define BASE_X        40
    #define OFFSET_Y_TEXT 50
    #define OFFSET_X_TEXT 180
    #define FONT_PATH "assets/fonts/arial.ttf"

namespace Snake
{
    class SnakeMenuScene : public SnakeScene
    {
        public:
            SnakeMenuScene();
            ~SnakeMenuScene() override = default;

            bool init() override;
    };
} // namespace Snake


#endif /* !SNAKEMENUSCENE_HPP_ */
