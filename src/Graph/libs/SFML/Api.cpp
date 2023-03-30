/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Api to access the lib in .so files
*/

#include "Api.hpp"
#include "SFMLDisplayModule.hpp"

extern "C" {
    Arcade::Graph::IDisplayModule *getDisplayModule()
    {
        return new Arcade::Graph::SFMLDisplayModule();
    }

    void destroyDisplayModule(Arcade::Graph::IDisplayModule *displayModule)
    {
        free(displayModule);
    }

    const char *getName()
    {
        return "SFML";
    }

    LibType getType()
    {
        return GRAPH;
    }
}
