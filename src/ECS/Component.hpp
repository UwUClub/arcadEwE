//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_COMPONENT_HPP
#define ARCADE_COMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS
{
    /**
     * @brief Base class for all components
     */
    struct Component : public IComponent {
        public:
        /**
         * @brief Construct a new Component object
         *
         * @param nType The type of the component
         * @param nId The id of the component
         */
        Component(CompType nType, const std::string &nId);

        /**
         * @brief Destroy the Component object
         */
        ~Component() override = default;
    };
} // namespace Arcade::ECS

#endif // ARCADE_COMPONENT_HPP
