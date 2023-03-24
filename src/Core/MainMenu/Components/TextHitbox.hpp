//
// Created by patatofour on 24/03/23.
//

#ifndef ARCADE_TEXTHITBOX_HPP
#define ARCADE_TEXTHITBOX_HPP

#include "Component.hpp"
#include "ArcadeStruct.hpp"

namespace Arcade::Core
{
    class TextHitbox : public ECS::Component
    {
        public:
        TextHitbox(const std::string &id, const Vector2f &box);
        explicit TextHitbox(const std::string &id);
        ~TextHitbox() override = default;

        [[nodiscard]] const Vector2f &getBox() const;
        void setBox(const Vector2f &box);

        private:
        Vector2f _box;
    };
} // namespace Arcade::Core

#endif // ARCADE_TEXTHITBOX_HPP
