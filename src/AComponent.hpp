//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ACOMPONENT_HPP
#define ARCADE_ACOMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS {
    class AComponent : public IComponent {
        public:
            AComponent(CompType type) : _type(type) {}
            ~AComponent() override = default;

            [[nodiscard]] Arcade::ECS::CompType getType() const override { return _type; }

        protected:
            CompType _type;
    };
}

#endif // ARCADE_ACOMPONENT_HPP
