/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** GameModule that will be passed to all systems, implemented in the core (it
** contains the Scene Manager created in the game lib)
*/

#pragma once

#include "AGameModule.hpp"

namespace Arcade::Game {

    class TestGame : public AGameModule {
        public:
        TestGame();
        ~TestGame() override = default;

        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) override;
    };
}
