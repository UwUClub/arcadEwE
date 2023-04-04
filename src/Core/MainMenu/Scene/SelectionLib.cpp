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
        std::string name = lib.second;
        name.erase(0, 16);
        name.erase(name.size() - 3, name.size());

        auto &entity = _entityManager->createEntity(name);
        auto text = std::shared_ptr<Arcade::Game::Text>(
            new Arcade::Game::Text(name+ "_text", name, FONT_PATH, { 0, 0, 0, 255 },
                { 255, 255, 255, 255 }, { BASE_X_TEXT, BASE_Y_TEXT, 0 }));
        auto hover = std::shared_ptr<Arcade::Game::IsHovered>(
            new Arcade::Game::IsHovered(name + "_hover"));
        if (lib.first == LibType::GAME) {
            text->pos.y = BASE_Y_TEXT + index_game * OFFSET_Y_TEXT;
            text->id += "_game";
            index_game++;
        } else {
            text->pos.y = BASE_Y_TEXT + index_graphic * OFFSET_Y_TEXT;
            text->pos.x += OFFSET_X_TEXT;
            text->id += "_graphic";
            index_graphic++;
        }
        entity.addComponent(text);
        entity.addComponent(hover);
    }
    this->addIcon();
    return true;
}

void Arcade::Game::SelectionLib::addIcon()
{
    auto &entity = _entityManager->createEntity("arcade_icon_sprite");
    const Arcade::Graph::TTYData tty = { "", { 255, 255, 255, 255 }, { 255, 0, 0, 255 } };
    auto sprite = std::shared_ptr<Arcade::Game::Sprite>(
        new Arcade::Game::Sprite("arcade_icon", "assets/images/menu_background.jpg", tty, { 0, 0, 0 }, { -360, -202, 1920, 1080 }, 0));
    entity.addComponent(sprite);
}
