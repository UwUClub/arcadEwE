/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerMenuScene
*/

#include "NibblerMenuScene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "NibblerText.hpp"
#include "NibblerIsHovered.hpp"
#include "NibblerIsHovering.hpp"
#include "MenuKeyboardHandler.hpp"

namespace Nibbler {
    NibblerMenuScene::NibblerMenuScene() : NibblerScene()
    {
    }

    bool NibblerMenuScene::init()
    {
        if (_entityManager == nullptr)
            _entityManager = std::make_unique<Arcade::ECS::EntityManager>();
        if (_systemManager == nullptr)
            _systemManager = std::make_unique<Arcade::ECS::SystemManager>();

        _systemManager->addSystem("IsHovering", std::make_unique<Nibbler::IsHovering>());
        _systemManager->addSystem("MenuKeyboardHandler", std::make_unique<Nibbler::MenuKeyboardHandler>());

        auto &entity = _entityManager->createEntity("playButton");

        auto text = std::shared_ptr<Nibbler::Text>(new Nibbler::Text("play_button_text",
            "PLAY", FONT_PATH, { 0, 0, 0, 255 }, { 255, 255, 255, 255 }, { BASE_X, 50, 0 }));
        text->pos.y = OFFSET_Y_TEXT;
        auto hover = std::shared_ptr<Nibbler::IsHovered>(new Nibbler::IsHovered("play_button_hover"));
        hover->isHovered = true;

        entity.addComponent(text);
        entity.addComponent(hover);
        return true;
    }
}
