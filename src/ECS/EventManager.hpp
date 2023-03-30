//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_EVENTMANAGER_HPP
#define ARCADE_EVENTMANAGER_HPP

#include <map>
#include "IEventManager.hpp"

namespace Arcade::ECS
{
    /**
     * @brief Event manager
     */
    class EventManager : public IEventManager
    {
        public:
        /**
         * @brief Construct a new Event Manager object
         */
        EventManager();
        /**
         * @brief Destroy the Event Manager object
         */
        ~EventManager() override = default;

        /**
         * @brief Check if the event manager is empty
         *
         * @return true If the event manager is empty
         * @return false If the event manager is not empty
         */
        [[nodiscard]] bool eventsIsEmpty() const override;
        /**
         * @brief Check if the event is triggered
         *
         * @param event The event to check
         * @return std::pair<bool,
         * std::optional<std::vector<std::optional<std::shared_ptr<IComponent>>>>> The bool is true
         * if the event is triggered, the optional is a container of components representing
         * different values attached to the event
         */
        [[nodiscard]] std::pair<bool,
            std::optional<std::vector<std::optional<std::shared_ptr<IComponent>>>>>
        isEventTriggered(const std::string &event) const override;
        /**
         * @brief Add an event to the event manager
         *
         * @param event The event to add
         * @param component The component to add to the event
         */
        void addEvent(const std::string &event,
            std::optional<std::shared_ptr<IComponent>> component) override;
        /**
         * @brief Remove all events from the event manager
         */
        void clearEvents() override;

        protected:
        std::map<std::string,
            std::optional<std::vector<std::optional<std::shared_ptr<IComponent>>>>>
            _events;
    };
} // namespace Arcade::ECS

#endif // ARCADE_EVENTMANAGER_HPP
