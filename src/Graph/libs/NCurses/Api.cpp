/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Api to access the lib in .so files
*/

#include "Api.hpp"
#include "NCursesDisplayModule.hpp"

extern "C" {
    Arcade::Graph::IDisplayModule *getDisplayModule()
    {
        return new Arcade::Graph::NCursesDisplayModule();
    }

    void destroyDisplayModule(Arcade::Graph::IDisplayModule *displayModule)
    {
        delete displayModule;
    }

    const char *getName()
    {
        return "NCurses";
    }

    LibType getType()
    {
        return GRAPH;
    }
}
