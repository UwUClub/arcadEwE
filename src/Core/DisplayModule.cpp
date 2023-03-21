//
// Created by patatofour on 21/03/23.
//

#include "DisplayModule.hpp"

Arcade::Core::DisplayModule::DisplayModule(libList &libList)
    : _libList(libList)
{
}

bool Arcade::Core::DisplayModule::changeGaphicLib(const std::string &libGraphicName)
{
    return false;
}

bool Arcade::Core::DisplayModule::changeGaphicLib()
{
    return false;
}

Arcade::ECS::ISystemManager &Arcade::Core::DisplayModule::getSystemManager()
{
    return *_systemManager;
}
