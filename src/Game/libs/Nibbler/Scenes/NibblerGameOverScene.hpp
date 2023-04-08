/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameOverScene
*/

#ifndef SNAKEGAMEOVERSCENE_HPP_
#define SNAKEGAMEOVERSCENE_HPP_
#include "NibblerScene.hpp"
#define BASE_X        40
#define OFFSET_Y_TEXT 50
#define OFFSET_X_TEXT 180
#define FONT_PATH     "assets/fonts/arial.ttf"

namespace Nibbler
{
    class NibblerGameOverScene : public NibblerScene
    {
        public:
        NibblerGameOverScene();
        ~NibblerGameOverScene() override = default;

        bool init() override;
        void setScore(size_t score);

        private:
        size_t _score;
    };
} // namespace Nibbler

#endif /* !SNAKEGAMEOVERSCENE_HPP_ */
