/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeMenuScene
*/

#include "SnakeMenuScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "SnakeText.hpp"
#include "SnakeIsHovered.hpp"
#include "SnakeIsHovering.hpp"
#include "MenuKeyboardHandler.hpp"

namespace Snake {
    SnakeMenuScene::SnakeMenuScene() : SnakeScene()
    {
    }

    bool SnakeMenuScene::init()
    {
        if (_entityManager == nullptr)
            _entityManager = std::make_unique<Arcade::ECS::EntityManager>();
        if (_systemManager == nullptr)
            _systemManager = std::make_unique<Arcade::ECS::SystemManager>();

        _systemManager->addSystem("IsHovering", std::make_unique<Snake::IsHovering>());
        _systemManager->addSystem("MenuKeyboardHandler", std::make_unique<Snake::MenuKeyboardHandler>());

        auto &entity = _entityManager->createEntity("playButton");

        auto text = std::shared_ptr<Snake::Text>(new Snake::Text("play_button_text",
            "PLAY", FONT_PATH, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 0, 0 }));
        text->pos.y = OFFSET_Y_TEXT;
        auto hover = std::shared_ptr<Snake::IsHovered>(new Snake::IsHovered("play_button_hover"));
        hover->isHovered = true;

        entity.addComponent(text);
        entity.addComponent(hover);
        return true;
    }
}
