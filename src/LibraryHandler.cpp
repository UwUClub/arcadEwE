//
// Created by patatofour on 16/03/23.
//

#include <dlfcn.h>
#include <functional>
#include "LibraryHandler.hpp"

namespace Arcade::Core
{
    void LibraryHandler::loadLibrary(const std::string &path, ISystemHandler *systemHandler)
    {
        void *lib = nullptr;

        dlerror();
        lib = dlopen(path.c_str(), RTLD_LAZY);
        if (lib == nullptr) {
            throw LibraryHandlerException("Cannot load library: " + std::string(dlerror()));
        }

        auto sym = dlsym(lib, "initLib");
        std::function<void(ISystemHandler *)> func = reinterpret_cast<void (*)(ISystemHandler *)>(sym);

        if (sym == nullptr) {
            throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
        }
        func(systemHandler);
        dlclose(lib);
    }
}
