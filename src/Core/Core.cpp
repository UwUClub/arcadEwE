//
// Created by patatofour on 20/03/23.
//

#include "Core.hpp"
#include "LibraryHandler.hpp"

Arcade::Core::Core::Core()
{
    auto libs = LibraryHandler::getLibraries();

    _displayModule = std::make_unique<DisplayModule>(libs);
    _gameModule = std::make_unique<GameModule>(libs);
}

void Arcade::Core::Core::run()
{

}
