/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerMenuScene
*/

#ifndef NIBBLERMENUSCENE_HPP_
    #define NIBBLERMENUSCENE_HPP_
    #include "NibblerScene.hpp"
    #define BASE_X        40
    #define OFFSET_Y_TEXT 50
    #define OFFSET_X_TEXT 180
    #define FONT_PATH "assets/fonts/arial.ttf"

namespace Nibbler
{
    class NibblerMenuScene : public NibblerScene
    {
        public:
            NibblerMenuScene();
            ~NibblerMenuScene() override = default;

            bool init() override;
    };
} // namespace Nibbler


#endif /* !NIBBLERMENUSCENE_HPP_ */
