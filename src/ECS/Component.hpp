//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_COMPONENT_HPP
#define ARCADE_COMPONENT_HPP

#include "IComponent.hpp"

namespace Arcade::ECS
{
    enum class CompType : int {
        TEXT = 0,
        SPRITE = 1,
        MUSIC = 2,
        TEXT_HOVER = 3,
        SPEED = 4,
        BUFFERTEXT = 5,
        DIRECTION = 6,
        COLLIDER = 7,
        TRANSFORM = 8,
    };

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
