//
// Created by patatofour on 21/03/23.
//

#include "DisplayModule.hpp"
#include "LibraryHandler.hpp"

Arcade::Core::DisplayModule::DisplayModule(const libList &libList)
{
    for (auto &lib : libList) {
        if (lib.first == LibType::GRAPH) {
            _libList.push_back(lib);
        }
    }
    _currentGraphicLib = _libList.front();
    _systemManager = LibraryHandler::loadDisplayLibrary("./lib/" + _currentGraphicLib.second);
}

void Arcade::Core::DisplayModule::changeGraphicLib(
    const std::string &libGraphicName)
{
    std::unique_ptr<ECS::ISystemManager> newSystemManager = nullptr;

    for (auto &lib : _libList) {
        if (lib.second == libGraphicName) {
            newSystemManager = LibraryHandler::loadDisplayLibrary("./lib/" + lib.second);
            _currentGraphicLib = lib;
            _systemManager = std::move(newSystemManager);
            break;
        }
    }
}

void Arcade::Core::DisplayModule::changeGraphicLib()
{
        std::unique_ptr<ECS::ISystemManager> newSystemManager = nullptr;
        auto it = _libList.begin();

        for (; it != _libList.end(); ++it) {
            if (it->second == _currentGraphicLib.second) {
                break;
            }
        }
        if (it == _libList.end()) {
                it = _libList.begin();
        }
        newSystemManager = LibraryHandler::loadDisplayLibrary("./lib/" + it->second);
        _currentGraphicLib = *it;
        _systemManager = std::move(newSystemManager);
}

Arcade::ECS::ISystemManager &Arcade::Core::DisplayModule::getSystemManager()
{
    return *_systemManager;
}
