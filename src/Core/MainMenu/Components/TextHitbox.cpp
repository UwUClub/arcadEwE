//
// Created by patatofour on 24/03/23.
//

#include "TextHitbox.hpp"

Arcade::Core::TextHitbox::TextHitbox(const std::string &id)
    : ECS::Component(ECS::CompType::HITBOX_TEXT, id)
    , _box({ 0, 0 })
{
}

Arcade::Core::TextHitbox::TextHitbox(const std::string &id, const Arcade::Vector2f &box)
    : ECS::Component(ECS::CompType::HITBOX_TEXT, id)
    , _box(box)
{
}

const Arcade::Vector2f &Arcade::Core::TextHitbox::getBox() const { return _box; }

void Arcade::Core::TextHitbox::setBox(const Arcade::Vector2f &box) { _box = box; }
