//
// Created by patatofour on 27/03/23.
//

#include "GameHandler.hpp"

Arcade::Core::GameHandler::GameHandler(const std::string &path)
    : _handle(nullptr)
{
    try {
        _handle = LibraryFinder::loadLibrary(path);
        auto sym = dlsym(_handle, "getGameModule");
        if (sym == nullptr)
            throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
        auto func = reinterpret_cast<IGameModule *(*) ()>(sym);
        _lib = func();
    } catch (const LibraryHandlerException &e) {
        std::cerr << e.what() << std::endl;
    }
}

Arcade::Core::GameHandler::~GameHandler()
{
    if (_handle) dlclose(_handle);
}