//
// Created by patatofour on 28/03/23.
//

#include "SelectionLib.hpp"
#include "LibraryFinder.hpp"
#include "Text.hpp"
#include "Sprite.hpp"
#include "Core.hpp"
#include "IsHovered.hpp"
#include "IsHovering.hpp"
#include "KeyboardHandler.hpp"

bool Arcade::Game::SelectionLib::init()
{
    auto libs = Arcade::Core::LibraryFinder::getLibraries();
    float index_game = 0;
    float index_graphic = 0;

    _systemManager->addSystem("isHovering", std::make_unique<Arcade::Game::IsHovering>());
    _systemManager->addSystem("keyboardHandler", std::make_unique<Arcade::Game::KeyboardHandler>());
    for (auto &lib : libs) {
        if (lib.second == "./lib/libarcade_mainMenu_game.so")
            continue;
        auto &entity = _entityManager->createEntity(lib.second);
        auto text = std::shared_ptr<Arcade::Game::Text>(
            new Arcade::Game::Text(lib.second + "_text", lib.second, FONT_PATH, { 0, 0, 0, 255 },
                { 255, 255, 255, 255 }, { BASE_X_TEXT, 0, 0 }));
        auto hover = std::shared_ptr<Arcade::Game::IsHovered>(
            new Arcade::Game::IsHovered(lib.second + "_hover"));
        if (lib.first == LibType::GAME) {
            text->pos.y = index_game * OFFSET_Y_TEXT;
            text->id += "_game";
            index_game++;
        } else {
            text->pos.y = index_graphic * OFFSET_Y_TEXT;
            text->pos.x += OFFSET_X_TEXT;
            text->id += "_graphic";
            index_graphic++;
        }
        entity.addComponent(text);
        entity.addComponent(hover);
    }
    auto &testEntity = _entityManager->createEntity("justatest");
    auto test = std::shared_ptr<Arcade::Game::Text>(
        new Arcade::Game::Text("justatest_text", "hello world!", FONT_PATH, { 0, 0, 0, 255 },
            { 255, 255, 255, 255 }, { 90, 0, 0 }));
    testEntity.addComponent(test);
    return true;
}

// void Arcade::Game::SelectionLib::addIcon()
// {
//     //auto &entity = _entityManager->createEntity("arcade_icon_sprite");
//     //const Arcade::Graph::TTYData tty = { "***", { 255, 255, 255, 255 }, { 255, 0, 0, 255 } };
//     // auto sprite = std::shared_ptr<Arcade::Game::Sprite>(
//     //     new Arcade::Game::Sprite("arcade_icon", "assets/images/arcade.png", tty, { 0, 0, 0 }, { 0, 0, 10, 10 }, 0));
//     // entity.addComponent(sprite);
// }
