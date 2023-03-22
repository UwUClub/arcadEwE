//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_EVENTMANAGER_HPP
#define ARCADE_EVENTMANAGER_HPP

#include <map>
#include "IEventManager.hpp"

namespace Arcade::ECS {
    class EventManager : public IEventManager {
        public:
            EventManager();
            ~EventManager() override = default;

            [[nodiscard]] bool eventsIsEmpty() const override;
            [[nodiscard]] std::pair<bool,
                std::optional<std::vector<std::optional<std::shared_ptr<IComponent>>>>>
            isEventTriggered(const std::string &event) const override;
            void addEvent(const std::string &event,
                std::optional<std::shared_ptr<IComponent>> component) override;
            void clearEvents() override;
            [[nodiscard]] const Arcade::Vector2f &getMousePosition() const override;
            void setMousePosition(const Arcade::Vector2f &mousePosition) override;

        protected:
            std::map<std::string, std::vector<std::optional<std::shared_ptr<IComponent>>>> _events;
            Arcade::Vector2f _mousePosition;
    };
}

#endif // ARCADE_EVENTMANAGER_HPP
