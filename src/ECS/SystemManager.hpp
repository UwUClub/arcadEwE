//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_SYSTEMMANAGER_HPP
#define ARCADE_SYSTEMMANAGER_HPP

#include "ISystemManager.hpp"

namespace Arcade::ECS
{
    /**
     * @brief The SystemManager class
     * @details The SystemManager is the class that manages all the systems.
     * It is responsible for adding, removing and updating all the systems.
     */
    class SystemManager : public ISystemManager
    {
        public:
        /**
         * @brief Construct a new SystemManager object
         */
        SystemManager() = default;
        /**
         * @brief Destroy the SystemManager object
         */
        ~SystemManager() override = default;

        /**
         * @brief Add a system to the system manager
         * @param name The name of the system
         * @param system The system to add
         */
        void addSystem(const std::string &name,
            std::unique_ptr<Arcade::ECS::ISystem> system) override;
        /**
         * @brief Remove a system from the system manager
         * @param name The name of the system to remove
         */
        void removeSystem(const std::string &name) override;
        /**
         * @brief Update all the systems
         * @param deltaTime The time since the last update
         * @param eventManager The event manager
         * @param currentEntityManager The current entity manager
         */
        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &currentEntityManager) override;

        private:
        /**
         * @brief The SystemManagerException class
         * @details The SystemManagerException is the exception thrown by the
         * SystemManager class.
         */
        class SystemManagerException : public std::exception
        {
            public:
            SystemManagerException(const std::string &message)
                : _message(message)
            {
            }

            ~SystemManagerException() override = default;

            const char *what() const noexcept override { return _message.c_str(); }

            private:
            std::string _message;
        };

        std::map<std::string, std::unique_ptr<ISystem>> _systems;
    };
} // namespace Arcade::ECS

#endif // ARCADE_SYSTEMMANAGER_HPP
