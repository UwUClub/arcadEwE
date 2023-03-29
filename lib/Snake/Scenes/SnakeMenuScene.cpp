/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeMenuScene
*/

#include "SnakeMenuScene.hpp"
#include "OnClickResume.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "SnakeText.hpp"
#include "SnakeIsHovered.hpp"

namespace Snake {
    SnakeMenuScene::SnakeMenuScene() : SnakeScene()
    {
    }

    bool SnakeMenuScene::init()
    {
        _systemManager->addSystem("IsHovering", std::make_unique<Snake::IsHovering>());

        auto &entity = _entityManager->createEntity("playButton");

        auto text = std::shared_ptr<Snake::Text>(new Snake::Text("play_button_text",
            "PLAY", FONT_PATH, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 0, 0 }));
        text->pos.y = OFFSET_Y_TEXT;
        auto hover = std::shared_ptr<Snake::IsHovered>(new Snake::IsHovered("play_button_hover"));

        entity.addComponent(text);
        entity.addComponent(hover);
        return true;
    }
}
