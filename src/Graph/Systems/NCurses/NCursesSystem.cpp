//
// Created by valegox on 22/03/23.
//

#include <ncurses.h>
#include "NCursesSystem.hpp"
#include "IScene.hpp"
#include "IGameModule.hpp"
#include "Scene.hpp"
#include "ArcadeStruct.hpp"
#include "Component.hpp"
#include "ISprite.hpp"
#include "IText.hpp"

Arcade::Graph::NCursesSystem::NCursesSystem()
{
    initscr();
    printw("Hello World");
}

Arcade::Graph::NCursesSystem::~NCursesSystem()
{
    endwin();
}

static void printContent(std::string content, int posX, int posY, Arcade::Graph::Color foregroundColor, Arcade::Graph::Color backgroundColor)
{
    if (has_colors()) {
        init_color(0, foregroundColor.r, foregroundColor.g, foregroundColor.b);
        init_color(1, backgroundColor.r, backgroundColor.g, backgroundColor.b);
        init_pair(2, 0, 1);
        attron(COLOR_PAIR(2));
    }
    mvprintw(posY, posX, content.c_str());
    if (has_colors()) {
        attroff(COLOR_PAIR(2));
    }
}

static void displaySprites(std::unique_ptr<Arcade::Game::IScene> &scene)
{
    for (auto &entity : scene->getEntityManager().getEntities()) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents = entity->getComponents(Arcade::ECS::CompType::SPRITE);

        for (auto spriteComponent : spriteComponents) {
            auto sprite = std::dynamic_pointer_cast<Arcade::Graph::ISprite>(spriteComponent);
            Arcade::Vector3f pos = (*sprite).getPos();
            Arcade::Graph::TTYData data = (*sprite).getTTYData();

            printContent(data.defaultChar, pos.x, pos.y, data.foreground, data.background);
        }
    }
}

static void displayTexts(std::unique_ptr<Arcade::Game::IScene> &scene)
{
    for (auto &entity : scene->getEntityManager().getEntities()) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

        for (auto textComponent : textComponents) {
            auto text = std::dynamic_pointer_cast<Arcade::Graph::IText>(textComponent);
            Arcade::Vector2f pos = (*text).getPos();
            Arcade::Graph::Color foregroundColor = (*text).getForegroundColor();
            Arcade::Graph::Color backgroundColor = (*text).getBackgroundColor();

            printContent((*text).getText(), pos.x, pos.y, foregroundColor, backgroundColor);
        }
    }
}

void Arcade::Graph::NCursesSystem::run([[maybe_unused]] std::size_t deltaTime, Arcade::ECS::IEventManager &,
    [[maybe_unused]] Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    std::unique_ptr<Arcade::Game::IScene> &scene = gameModule.getSceneManager().getCurrentScene();

    displaySprites(scene);
    displayTexts(scene);

    // getch(); // get press event
    refresh();
}
