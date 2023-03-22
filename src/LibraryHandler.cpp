//
// Created by patatofour on 16/03/23.
//

#include <dlfcn.h>
#include <functional>
#include <dirent.h>
#include "LibraryHandler.hpp"

namespace Arcade::Core
{
    std::unique_ptr<Arcade::Game::ISceneManager>
    LibraryHandler::loadGameLibrary(const std::string &path)
    {
        void *lib = nullptr;
        void *sym = nullptr;
        std::function<std::unique_ptr<Arcade::Game::ISceneManager>()> func = nullptr;

        lib = LibraryHandler::loadLibrary(path);
        sym = dlsym(lib, "initLib");
        if (sym == nullptr) {
            throw LibraryHandlerException(
                "Cannot load symbol: " + std::string(dlerror()));
        }
        func = reinterpret_cast<
            std::unique_ptr<Arcade::Game::ISceneManager> (*)()>(sym);
        dlclose(lib);
        return func();
    }

    std::unique_ptr<Arcade::ECS::ISystemManager>
    LibraryHandler::loadDisplayLibrary(const std::string &path)
    {
        void *lib = nullptr;
        void *sym = nullptr;
        std::function<std::unique_ptr<Arcade::ECS::ISystemManager>()> func = nullptr;

        lib = LibraryHandler::loadLibrary(path);
        sym = dlsym(lib, "initLib");
        if (sym == nullptr) {
            throw LibraryHandlerException(
                "Cannot load symbol: " + std::string(dlerror()));
        }
        func = reinterpret_cast<
            std::unique_ptr<Arcade::ECS::ISystemManager> (*)()>(sym);
        dlclose(lib);
        return func();
    }

    void *LibraryHandler::loadLibrary(const std::string &path)
    {
        void *lib = nullptr;

        dlerror();
        lib = dlopen(path.c_str(), RTLD_LAZY);
        if (lib == nullptr) {
            throw LibraryHandlerException(
                "Cannot load library: " + std::string(dlerror()));
        }
        return lib;
    }

    libInfo LibraryHandler::getLibType(const std::string &path)
    {
        auto lib = LibraryHandler::loadLibrary(path);
        void *sym = nullptr;
        std::pair<LibType, std::string> type;
        std::function<LibType()> typeFunc = nullptr;
        std::function<const char *()> nameFunc = nullptr;

        dlerror();
        sym = dlsym(lib, "getType");
        if (sym == nullptr) {
            throw LibraryHandlerException(
                "Cannot load symbol: " + std::string(dlerror()));
        }
        typeFunc = reinterpret_cast<LibType (*)()>(sym);
        sym = dlsym(lib, "getName");
        if (sym == nullptr) {
            throw LibraryHandlerException(
                "Cannot load symbol: " + std::string(dlerror()));
        }
        nameFunc = reinterpret_cast<const char *(*) ()>(sym);
        type.first = typeFunc();
        type.second = nameFunc();
        dlclose(lib);
        return type;
    }

    libList LibraryHandler::getLibraries()
    {
        libList libs;
        DIR *dir = nullptr;
        struct dirent *ent = nullptr;

        dir = opendir("./lib");
        if (dir == nullptr) {
            throw LibraryHandlerException("Cannot open directory: ./lib");
        }
        while ((ent = readdir(dir)) != nullptr) {
            std::string name(ent->d_name);
            if (name.starts_with("arcade_") && name.ends_with(".so"))
                libs.push_back(getLibType(std::string("./lib/") + name));
        }
        closedir(dir);
        return libs;
    }
} // namespace Arcade::Core
