/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** SFML - DisplayModule
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLDisplayModule.hpp"

namespace Arcade::Graph
{

    SFMLDisplayModule::SFMLDisplayModule()
    {
        _window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arcade");
        _window->clear(sf::Color::Green);
        _textHandler = new TextHandler();
        // this->_spriteHandler = new SpriteHandler();
        // this->_musicHandler = new MusicHandler();
        _eventHandler = new EventHandler();
    }

    SFMLDisplayModule::~SFMLDisplayModule()
    {
        _window->close();
        delete _textHandler;
        // free(this->_spriteHandler);
        // free(this->_musicHandler);
        delete _eventHandler;
    }

    void SFMLDisplayModule::update([[maybe_unused]] double delta,
        [[maybe_unused]] Arcade::ECS::IEventManager &eventManager,
        [[maybe_unused]] Arcade::ECS::IEntityManager &entityManager)
    {
        _window->clear(sf::Color::Green);
        // this->_spriteHandler->run(delta, eventManager, entityManager);
        _textHandler->run(entityManager, _window);
        _window->display();

        // this->_musicHandler->run(delta, eventManager, entityManager);
        _eventHandler->run(eventManager, _window);
    }
} // namespace Arcade::Graph
