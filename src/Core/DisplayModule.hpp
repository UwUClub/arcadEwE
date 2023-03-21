//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_DISPLAYMODULE_HPP
#define ARCADE_DISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include "LibraryHandler.hpp"
#include "ISystemManager.hpp"
#include <memory>

namespace Arcade::Core
{
    class DisplayModule : public IDisplayModule
    {
        public:
            DisplayModule(libList &libList);
            virtual ~DisplayModule() = default;

            ECS::ISystemManager &getSystemManager() override;

            bool changeGaphicLib(const std::string &libGraphicName) override;
            bool changeGaphicLib() override;

            private:
            std::unique_ptr<ECS::ISystemManager> _systemManager;
            libList _libList;
    };
}

#endif // ARCADE_DISPLAYMODULE_HPP
