//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ACOMPONENT_HPP
#define ARCADE_ACOMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS {
    enum class CompType;

    class AComponent : public IComponent {
        public:
            AComponent(CompType type, std::string id);
            ~AComponent() override = default;

            [[nodiscard]] Arcade::ECS::CompType getType() const override;
            [[nodiscard]] const std::string &getId() const override;

        protected:
            CompType _type;
            std::string _id;
    };
}

#endif // ARCADE_ACOMPONENT_HPP
