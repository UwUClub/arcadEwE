//
// Created by patatofour on 27/03/23.
//

#include "GameHandler.hpp"

Arcade::Core::GameHandler::GameHandler(const std::string &path)
    : _handle(nullptr)
    , _lib(nullptr)
{
    try {
        _handle = LibraryFinder::loadLibrary(path);
        auto sym = dlsym(_handle, "getGameModule");
        if (sym == nullptr)
            throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
        auto func = reinterpret_cast<Game::IGameModule *(*) ()>(sym);
        _lib = std::unique_ptr<Game::IGameModule>(func());
    } catch (const LibraryHandlerException &e) {
        std::cerr << e.what() << std::endl;
    }
}

Arcade::Core::GameHandler::~GameHandler()
{
    if (_handle == nullptr) return;
    auto sym = dlsym(_handle, "destroyGameModule");

    if (sym == nullptr)
        return;
    auto func = reinterpret_cast<void (*)(Game::IGameModule *)>(sym);
    func(_lib.get());
    dlclose(_handle);
}
