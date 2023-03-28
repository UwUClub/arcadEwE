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

namespace Snake {
    SnakeMenuScene::SnakeMenuScene() : SnakeScene()
    {
        _systemManager->addSystem("OnClickResume", std::make_unique<Snake::OnClickResume>());

        auto &entity = _entityManager->createEntity("resumeButton");

        auto text = std::shared_ptr<Arcade::Game::Text>(new Arcade::Game::Text("resume_button_text",
            resumeButton, FONT_PATH, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 0, 0 }));
        text->pos.y = index_game * OFFSET_Y_TEXT;
        auto hover = std::shared_ptr<Arcade::Game::IsHovered>(new Arcade::Game::IsHovered("resume_button_hover"));

        entity.addComponent(text);
        entity.addComponent(hover);
    }
}
