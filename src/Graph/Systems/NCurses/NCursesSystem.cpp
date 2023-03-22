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

Arcade::Graph::NCursesSystem::NCursesSystem()
{
    initscr();
    printw("Hello World");
}

Arcade::Graph::NCursesSystem::~NCursesSystem()
{
    endwin();
}

static void displaySprites(std::unique_ptr<Arcade::Game::IScene> &scene)
{
    for (auto &entity : scene->getEntityManager().getEntities()) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents = entity->getComponents(Arcade::ECS::CompType::SPRITE);

        for (auto spriteComponent : spriteComponents) {
            [[maybe_unused]] auto sprite = std::dynamic_pointer_cast<Arcade::Graph::ISprite>(spriteComponent);
            Arcade::Vector3f pos = (*sprite).getPos();
            Arcade::Graph::TTYData data = (*sprite).getTTYData();
            init_pair(0, data.foregroundColor, data.backgroundColor);
            attron(COLOR_PAIR(0));
            mvprintw(pos.y, pos.x, data.defaultChar.c_str());
            attroff(COLOR_PAIR(0));
        }
    }
}

void Arcade::Graph::NCursesSystem::run([[maybe_unused]] std::size_t deltaTime, Arcade::ECS::IEventManager &,
    [[maybe_unused]] Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    std::unique_ptr<Arcade::Game::IScene> &scene = gameModule.getSceneManager().getCurrentScene();

    displaySprites(scene);

    // getch(); // get press event
    refresh();
}
