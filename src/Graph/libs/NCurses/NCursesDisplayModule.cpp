/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** NCurses - DisplayModule
*/

#include <ncurses.h>
#include <iostream>
#include "NCursesDisplayModule.hpp"

namespace Arcade::Graph
{

    NCursesDisplayModule::NCursesDisplayModule()
    {
        initscr();
        raw();
        noecho();
        curs_set(0);
        start_color();
        keypad(stdscr, TRUE);
        this->_spriteHandler = new SpriteHandler();
        this->_textHandler = new TextHandler();
        this->_eventHandler = new EventHandler();
    }

    NCursesDisplayModule::~NCursesDisplayModule()
    {
        curs_set(1);
        noraw();
        echo();
        endwin();
        free(this->_spriteHandler);
        free(this->_textHandler);
        free(this->_eventHandler);
    }

    void NCursesDisplayModule::update([[maybe_unused]] float delta, [[maybe_unused]] Arcade::ECS::IEventManager &eventManager,
        [[maybe_unused]] Arcade::ECS::IEntityManager &entityManager)
    {
        refresh();

        this->_spriteHandler->run(delta, eventManager, entityManager);
        this->_textHandler->run(delta, eventManager, entityManager);
        this->_eventHandler->run(delta, eventManager, entityManager);
    }
} // namespace Arcade::Graph
