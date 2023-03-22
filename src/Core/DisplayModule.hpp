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
            DisplayModule(const libList &libList);
            virtual ~DisplayModule() = default;

            ECS::ISystemManager &getSystemManager() override;

            void changeGraphicLib(const std::string &libGraphicName) override;
            void changeGraphicLib() override;

            private:
            std::unique_ptr<ECS::ISystemManager> _systemManager;
            libList _libList;
            libInfo _currentGraphicLib;
    };
}

#endif // ARCADE_DISPLAYMODULE_HPP
