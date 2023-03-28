//
// Created by patatofour on 27/03/23.
//

#include "DisplayHandler.hpp"

Arcade::Core::DisplayHandler::DisplayHandler(const std::string &path)
    : _handle(nullptr)
{
    try {
        _handle = LibraryFinder::loadLibrary(path);
        auto sym = dlsym(_handle, "getDisplayModule");
        if (sym == nullptr)
            throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
        auto func = reinterpret_cast<Graph::IDisplayModule *(*) ()>(sym);
        _lib = std::unique_ptr<Graph::IDisplayModule>(func());
    } catch (const LibraryHandlerException &e) {
        std::cerr << e.what() << std::endl;
    }
}

Arcade::Core::DisplayHandler::~DisplayHandler()
{
    if (_handle) dlclose(_handle);
}
} // namespace Arcade::Core
