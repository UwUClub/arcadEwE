//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_SYSTEMMANAGER_HPP
#define ARCADE_SYSTEMMANAGER_HPP

#include <map>
#include <memory>
#include "ISystemManager.hpp"

namespace Arcade::ECS {
    class SystemManager : public ISystemManager {
        public:
            SystemManager() = default;
            ~SystemManager() override = default;

            void addSystem(
                const std::string &name, Arcade::ECS::ISystem *system) override;
            void removeSystem(const std::string &name) override;
            void update(std::size_t deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::Core::IDisplayModule &displayModule,
                Arcade::Core::IGameModule &gameModule) override;

        private:
            std::map<std::string, std::unique_ptr<ISystem>> _systems;
    };
}

#endif // ARCADE_SYSTEMMANAGER_HPP
