//
// Created by patatofour on 16/03/23.
//

#include <dlfcn.h>
#include <functional>
#include "LibraryHandler.hpp"

namespace Arcade::Core
{
    void LibraryHandler::loadLibrary(const std::string &path, ECS::ISystemManager *systemManager)
    {
        void *lib = nullptr;
        void *sym = nullptr;
        std::function<void(ECS::ISystemManager *)> func = nullptr;

        dlerror();
        lib = dlopen(path.c_str(), RTLD_LAZY);
        if (lib == nullptr) {
            throw LibraryHandlerException("Cannot load library: " + std::string(dlerror()));
        }
        sym = dlsym(lib, "initLib");
        if (sym == nullptr) {
            throw LibraryHandlerException("Cannot load symbol: " + std::string(dlerror()));
        }
        func = reinterpret_cast<void (*)(ECS::ISystemManager *)>(sym);
        func(systemManager);
        dlclose(lib);
    }
}
