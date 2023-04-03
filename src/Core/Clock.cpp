//
// Created by patatofour on 03/04/23.
//

#include <iostream>
#include "Clock.hpp"

Arcade::Core::Clock::Clock()
    : _lastTime(std::chrono::steady_clock::now())
{
}

float Arcade::Core::Clock::getDeltaTime()
{
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<float> delta = now - _lastTime;

    _lastTime = now;
    return delta.count();
}
