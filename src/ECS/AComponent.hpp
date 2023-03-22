//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ACOMPONENT_HPP
#define ARCADE_ACOMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS {
    enum class CompType {
        SPRITE,
        TEXT,
        MUSIC
    };

    class AComponent : public IComponent {
        public:
            AComponent(CompType type, const std::string &id);
            ~AComponent() override = default;

            [[nodiscard]] CompType getType() const override;
            [[nodiscard]] const std::string &getId() const override;

        protected:
            CompType _type;
            const std::string _id;
    };
}

#endif // ARCADE_ACOMPONENT_HPP
