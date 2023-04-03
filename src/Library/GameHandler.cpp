//
// Created by patatofour on 27/03/23.
//

#include "GameHandler.hpp"
#include "DisplayHandler.hpp"

Arcade::Core::GameHandler::GameHandler(const std::string &path)
    : _handle(nullptr)
    , _lib(nullptr)
{
    _handle = LibraryFinder::loadLibrary(path);
    auto sym = dlsym(_handle, "getGameModule");
    if (sym == nullptr)
        throw DisplayHandler::LibraryHandlerException(
            "Cannot load symbol: " + std::string(dlerror()));
    auto func = reinterpret_cast<Game::IGameModule *(*) ()>(sym);
    _lib = func();
}

Arcade::Core::GameHandler::~GameHandler()
{
    if (_handle == nullptr)
        return;
    auto sym = dlsym(_handle, "destroyGameModule");

    if (sym == nullptr)
        return;
    auto func = reinterpret_cast<void (*)(Game::IGameModule *)>(sym);
    func(_lib);
    dlclose(_handle);
}
