//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_SYSTEMMANAGER_HPP
#define ARCADE_SYSTEMMANAGER_HPP

#include "ISystemManager.hpp"

namespace Arcade::ECS
{
    class SystemManager : public ISystemManager
    {
        public:
        SystemManager() = default;
        ~SystemManager() override = default;

        void addSystem(const std::string &name,
            std::unique_ptr<Arcade::ECS::ISystem> system) override;
        void removeSystem(const std::string &name) override;
        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) override;

        private:
        class SystemManagerException : public std::exception
        {
                public:
                SystemManagerException(const std::string &message) : _message(message) {}
                ~SystemManagerException() override = default;

                const char *what() const noexcept override { return _message.c_str(); }

                private:
                std::string _message;
        };
        std::map<std::string, std::unique_ptr<ISystem>> _systems;
    };
} // namespace Arcade::ECS

#endif // ARCADE_SYSTEMMANAGER_HPP
