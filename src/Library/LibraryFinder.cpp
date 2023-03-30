//
// Created by patatofour on 27/03/23.
//

#include <functional>
#include <dlfcn.h>
#include <dirent.h>
#include "LibraryFinder.hpp"

Arcade::Core::libInfo Arcade::Core::LibraryFinder::getLibType(const std::string &path)
{
    auto lib = LibraryFinder::loadLibrary(path);
    void *sym = nullptr;
    std::pair<LibType, std::string> type;
    std::function<LibType()> typeFunc = nullptr;
    std::function<const char *()> nameFunc = nullptr;

    dlerror();
    sym = dlsym(lib, "getType");
    if (sym == nullptr) {
        throw LibraryFinderException("Cannot load symbol: " + std::string(dlerror()));
    }
    typeFunc = reinterpret_cast<LibType (*)()>(sym);
    type.first = typeFunc();
    type.second = path;
    dlclose(lib);
    return type;
}

Arcade::Core::libList Arcade::Core::LibraryFinder::getLibraries()
{
    libList libs;
    DIR *dir = nullptr;
    struct dirent *ent = nullptr;

    dir = opendir("./lib");
    if (dir == nullptr) {
        throw LibraryFinderException("Cannot open directory: ./lib");
    }
    while ((ent = readdir(dir)) != nullptr) {
        std::string name(ent->d_name);
        if (name.starts_with("libarcade_") && name.ends_with(".so"))
            libs.push_back(getLibType(std::string("./lib/") + name));
    }
    closedir(dir);
    return libs;
}

void *Arcade::Core::LibraryFinder::loadLibrary(const std::string &path)
{
    void *lib = nullptr;

    dlerror();
    lib = dlopen(path.c_str(), RTLD_LAZY);
    if (lib == nullptr) {
        throw LibraryFinderException("Cannot load library: " + std::string(dlerror()));
    }
    return lib;
}
