//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_COMPONENT_HPP
#define ARCADE_COMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS {
    enum class CompType;

    class Component : public IComponent {
        public:
        Component(CompType type, const std::string &id);
            ~Component() override = default;

            [[nodiscard]] CompType getType() const override;
            [[nodiscard]] const std::string &getId() const override;

        protected:
            CompType _type;
            const std::string _id;
    };
}

#endif // ARCADE_COMPONENT_HPP
