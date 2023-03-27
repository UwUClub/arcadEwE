//
// Created by patatofour on 27/03/23.
//

#include "DisplayHandler.hpp"

namespace Arcade::Core
{
    DisplayHandler::DisplayHandler(const std::string &path)
        : _handle(nullptr)
    {
        try {
            _handle = LibraryFinder::loadLibrary(path);
            auto sym = dlsym(_handle, "getDisplayModule");
            if (sym == nullptr)
                throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
            auto func = reinterpret_cast<IDisplayModule *(*) ()>(sym);
            _lib = func();
        } catch (const LibraryHandlerException &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    DisplayHandler::~DisplayHandler()
    {
        if (_handle) dlclose(_handle);
    }
} // namespace Arcade::Core
