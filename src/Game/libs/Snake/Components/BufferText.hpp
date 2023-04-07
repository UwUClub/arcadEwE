//
// Created by patatofour on 07/04/23.
//

#ifndef ARCADE_BUFFERTEXT_HPP
#define ARCADE_BUFFERTEXT_HPP

#include "Component.hpp"

namespace Snake
{
    class BufferText : public Arcade::ECS::Component
    {
        public:
        explicit BufferText(const std::string &id);
        ~BufferText() override = default;

        bool isBuffer;
    };
} // namespace Snake

#endif // ARCADE_BUFFERTEXT_HPP
