/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** NCurses - DisplayModule
*/

#pragma once

#include <vector>
#include "IDisplayModule.hpp"
#include "SpriteHandler.hpp"
#include "TextHandler.hpp"
#include "EventHandler.hpp"

namespace Arcade::Graph
{
    class NCursesDisplayModule : public IDisplayModule
    {
        public:
        NCursesDisplayModule();
        ~NCursesDisplayModule() override;

        void update(double delta, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager) override;

        protected:
        SpriteHandler *_spriteHandler;
        TextHandler *_textHandler;
        EventHandler *_eventHandler;
    };
} // namespace Arcade::Graph
