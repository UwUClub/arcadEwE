//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_EVENTMANAGER_HPP
#define ARCADE_EVENTMANAGER_HPP

#include "IEventManager.hpp"

namespace Arcade::ECS {
    class EventManager : public IEventManager {
        public:
            EventManager();
            ~EventManager() override = default;

            [[nodiscard]] bool eventsIsEmpty() const override;
            [[nodiscard]] bool isEventInQueue(const std::string &eventName) const override;
            void addEvent(const std::string &eventName) override;
            const std::string &popEvent() override;
            void clearEvents() override;
            [[nodiscard]] const Arcade::Vector2f &getMousePosition() const override;
            void setMousePosition(const Arcade::Vector2f &mousePosition) override;

        protected:
            std::vector<std::string> _events;
            Arcade::Vector2f _mousePosition{};
    };
}

#endif // ARCADE_EVENTMANAGER_HPP
