/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameOverScene
*/

#include "NibblerGameOverScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "NibblerText.hpp"
#include "BufferWriterManager.hpp"
#include "BufferText.hpp"

namespace Nibbler
{
    NibblerGameOverScene::NibblerGameOverScene()
        : NibblerScene()
    {
    }

    bool NibblerGameOverScene::init()
    {
        if (_entityManager == nullptr)
            _entityManager = std::make_unique<Arcade::ECS::EntityManager>();
        if (_systemManager == nullptr)
            _systemManager = std::make_unique<Arcade::ECS::SystemManager>();

        _systemManager->addSystem("BufferWriterManager",
            std::make_unique<Nibbler::BufferWriterManager>(_score));

        auto &entity = _entityManager->createEntity("Text");
        auto &entity2 = _entityManager->createEntity("BufferText");

        auto text = std::shared_ptr<Nibbler::Text>(
            new Nibbler::Text("Text", "Enter your username and press enter to save your score",
                FONT_PATH, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 50, 0 }));
        text->pos.y = OFFSET_Y_TEXT;

        auto text2 = std::shared_ptr<Nibbler::Text>(new Nibbler::Text("Text", "", FONT_PATH,
            { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 50, 0 }));
        text2->pos.y = OFFSET_Y_TEXT + 10;
        auto bufferText = std::shared_ptr<Nibbler::BufferText>(new Nibbler::BufferText("BufferText"));

        entity.addComponent(text);
        entity2.addComponent(text2);
        entity2.addComponent(bufferText);
        return true;
    }

    void NibblerGameOverScene::setScore(size_t score)
    {
        _score = score;
    }
} // namespace Nibbler
