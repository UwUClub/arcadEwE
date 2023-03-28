/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeMenuScene
*/

#ifndef SNAKEMENUSCENE_HPP_
    #define SNAKEMENUSCENE_HPP_
    #include "SnakeScene.hpp"
    #define BASE_X        20
    #define OFFSET_Y_TEXT 50
    #define OFFSET_X_TEXT 180

namespace Snake
{
    class SnakeMenuScene : public SnakeScene
    {
        public:
            SnakeMenuScene();
            ~SnakeMenuScene() override = default;
    };
} // namespace Snake


#endif /* !SNAKEMENUSCENE_HPP_ */
