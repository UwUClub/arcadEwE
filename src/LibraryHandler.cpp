//
// Created by patatofour on 16/03/23.
//

#include <dlfcn.h>
#include "LibraryHandler.hpp"

namespace Arcade::Core
{
    std::unique_ptr<Arcade::Game::IGame *> LibraryHandler::loadGameLibrary(const std::string &path)
    {
        void *lib = nullptr;
        Arcade::Game::IGame *game = nullptr;

        dlerror();
        lib = dlopen(path.c_str(), RTLD_LAZY);
        if (lib == nullptr) {
            throw LibraryHandlerException("Cannot load library: " + std::string(dlerror()));
        }
        game = static_cast<Arcade::Game::IGame *>(*loadSymbol(lib, "gameMaker"));
        dlclose(lib);
        return std::make_unique<Arcade::Game::IGame *>(game);
    }

    std::unique_ptr<Arcade::Graph::IGraph *> LibraryHandler::loadGraphicLibrary(const std::string &path)
    {
        void *lib = nullptr;
        Arcade::Graph::IGraph *graph = nullptr;

        dlerror();
        lib = dlopen(path.c_str(), RTLD_LAZY);
        if (lib == nullptr) {
            throw LibraryHandlerException("Cannot load library: " + std::string(dlerror()));
        }
        graph = static_cast<Arcade::Graph::IGraph *>(*loadSymbol(lib, "graphMaker"));
        dlclose(lib);
        return std::make_unique<Arcade::Graph::IGraph *>(graph);
    }

    std::unique_ptr<void *> LibraryHandler::loadSymbol(void *handle, const std::string &symbol)
    {
        void *sym = nullptr;

        dlerror();
        sym = dlsym(handle, symbol.c_str());
        if (sym == nullptr) {
            throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
        }
        return std::make_unique<void *>(sym);
    }
}
