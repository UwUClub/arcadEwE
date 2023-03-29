//
// Created by patatofour on 28/03/23.
//

#include "SelectionLib.hpp"
#include "LibraryFinder.hpp"
#include "Text.hpp"
#include "Core.hpp"
#include "IsHovered.hpp"
#include "IsHovering.hpp"
#include "KeyboardHandler.hpp"

Arcade::Game::SelectionLib::SelectionLib()
    : MainMenuScene()
{
}

bool Arcade::Game::SelectionLib::init()
{
    auto libs = Arcade::Core::LibraryFinder::getLibraries();
    float index_game = 0;
    float index_graphic = 0;

    _systemManager->addSystem("isHovering", std::make_unique<Arcade::Game::IsHovering>());
    _systemManager->addSystem("keyboardHandler", std::make_unique<Arcade::Game::KeyboardHandler>());
    for (auto &lib : libs) {
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
    return true;
}
