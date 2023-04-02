/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** SFML - DisplayModule
*/

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"
#include "TextHandler.hpp"
// #include "SpriteHandler.hpp"
// #include "MusicHandler.hpp"
#include "EventHandler.hpp"

namespace Arcade::Graph {
    class SFMLDisplayModule : public IDisplayModule {
        public:
        SFMLDisplayModule();
        ~SFMLDisplayModule() override;

        void update(float delta, Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager) override;

        protected:
        sf::RenderWindow *_window;
        TextHandler *_textHandler;
        // SpriteHandler *_spriteHandler;
        // MusicHandler *_musicHandler;
        EventHandler *_eventHandler;
    };
}
