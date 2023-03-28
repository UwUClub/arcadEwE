//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_COMPONENT_HPP
#define ARCADE_COMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS
{
    struct Component : public IComponent {
        public:
        Component(CompType nType, const std::string &nId)
        {
            type = nType;
            id = nId;
        }

        ~Component() override = default;
    };
} // namespace Arcade::ECS

#endif // ARCADE_COMPONENT_HPP
