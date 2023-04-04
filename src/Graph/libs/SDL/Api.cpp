//
// Created by patatofour on 03/04/23.
//

#include <iostream>
#include "Api.hpp"
#include "SdlDisplayModule.hpp"

extern "C" {
Arcade::Graph::IDisplayModule *getDisplayModule()
{
    return new Arcade::Graph::SDLDisplayModule();
}

void destroyDisplayModule(Arcade::Graph::IDisplayModule *displayModule)
{
    delete displayModule;
}

const char *getName()
{
    return "SDL";
}

LibType getType()
{
    return GRAPH;
}
}
