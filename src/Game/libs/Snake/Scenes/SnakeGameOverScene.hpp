/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameOverScene
*/

#ifndef SNAKEGAMEOVERSCENE_HPP_
    #define SNAKEGAMEOVERSCENE_HPP_
    #include "SnakeScene.hpp"
    #define BASE_X        40
    #define OFFSET_Y_TEXT 50
    #define OFFSET_X_TEXT 180
    #define FONT_PATH "assets/fonts/arial.ttf"

namespace Snake
{
    class SnakeGameOverScene : public SnakeScene
    {
        public:
            SnakeGameOverScene();
            ~SnakeGameOverScene() override = default;

            bool init() override;
    };
} // namespace Snake


#endif /* !SNAKEGAMEOVERSCENE_HPP_ */
