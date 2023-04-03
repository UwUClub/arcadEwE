//
// Created by patatofour on 03/04/23.
//

#ifndef ARCADE_CLOCK_HPP
#define ARCADE_CLOCK_HPP

#include <chrono>

namespace Arcade::Core
{
    class Clock
    {
        public:
        Clock();
        ~Clock() = default;

        float getDeltaTime();

        private:
        std::chrono::time_point<std::chrono::steady_clock> _lastTime;
    };
} // namespace Arcade::Core

#endif // ARCADE_CLOCK_HPP
