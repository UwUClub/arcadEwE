/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameOverScene
*/

#include "SnakeGameOverScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "SnakeText.hpp"
#include "BufferWriterManager.hpp"
#include "BufferText.hpp"

namespace Snake
{
    SnakeGameOverScene::SnakeGameOverScene()
        : SnakeScene()
    {
    }

    bool SnakeGameOverScene::init()
    {
        if (_entityManager == nullptr)
            _entityManager = std::make_unique<Arcade::ECS::EntityManager>();
        if (_systemManager == nullptr)
            _systemManager = std::make_unique<Arcade::ECS::SystemManager>();

        _systemManager->addSystem("BufferWriterManager",
            std::make_unique<Snake::BufferWriterManager>(_score));

        auto &entity = _entityManager->createEntity("Text");
        auto &entity2 = _entityManager->createEntity("BufferText");

        auto text = std::shared_ptr<Snake::Text>(
            new Snake::Text("Text", "Enter your username and press enter to save your score",
                FONT_PATH, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 50, 0 }));
        text->pos.y = OFFSET_Y_TEXT;

        auto text2 = std::shared_ptr<Snake::Text>(new Snake::Text("Text", "", FONT_PATH,
            { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 50, 0 }));
        text2->pos.y = OFFSET_Y_TEXT + 10;
        auto bufferText = std::shared_ptr<Snake::BufferText>(new Snake::BufferText("BufferText"));

        entity.addComponent(text);
        entity2.addComponent(text2);
        entity2.addComponent(bufferText);
        return true;
    }

    void SnakeGameOverScene::setScore(size_t score)
    {
        _score = score;
    }
} // namespace Snake
