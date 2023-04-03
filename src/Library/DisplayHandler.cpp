//
// Created by patatofour on 27/03/23.
//

#include "DisplayHandler.hpp"

Arcade::Core::DisplayHandler::DisplayHandler(const std::string &path)
    : _handle(nullptr)
    , _lib(nullptr)
{
    _handle = LibraryFinder::loadLibrary(path);
    auto sym = dlsym(_handle, "getDisplayModule");
    if (sym == nullptr)
        throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
    auto func = reinterpret_cast<Graph::IDisplayModule *(*) ()>(sym);
    _lib = func();
}

Arcade::Core::DisplayHandler::~DisplayHandler()
{
    if (_handle == nullptr)
        return;
    auto sym = dlsym(_handle, "destroyDisplayModule");

    if (sym == nullptr)
        return;
    [[maybe_unused]] auto func = reinterpret_cast<void (*)(Graph::IDisplayModule *)>(sym);
    func(_lib);
    dlclose(_handle);
}
