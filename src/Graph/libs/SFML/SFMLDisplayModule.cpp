/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** SFML - DisplayModule
*/

#include <iostream>
#include "SFMLDisplayModule.hpp"

namespace Arcade::Graph {

    SFMLDisplayModule::SFMLDisplayModule()
    {
        // this->_window.create(sf::VideoMode(800, 600), "Arcade");

        // this->_textHandler = new TextHandler();
        // this->_spriteHandler = new SpriteHandler();
        // this->_musicHandler = new MusicHandler();
        // this->_eventHandler = new EventHandler();
    }

    SFMLDisplayModule::~SFMLDisplayModule()
    {
        // TODO: close window

        // free(this->_textHandler);
        // free(this->_spriteHandler);
        // free(this->_musicHandler);
        // free(this->_eventHandler);
    }

    void SFMLDisplayModule::update([[maybe_unused]] float delta, [[maybe_unused]] Arcade::ECS::IEventManager &eventManager, [[maybe_unused]] Arcade::ECS::IEntityManager &entityManager)
    {
        // this->_window.clear();
        // this->_spriteHandler->run(delta, eventManager, entityManager);
        // this->_textHandler->run(entityManager, this->_window);
        // this->_window.display();

        // this->_musicHandler->run(delta, eventManager, entityManager);
        // this->_eventHandler->run(delta, eventManager, entityManager);
    }
}
