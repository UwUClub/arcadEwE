//
// Created by patatofour on 28/03/23.
//

#include "MainMenu.hpp"
#include "SelectionLib.hpp"

Arcade::Game::MainMenu::MainMenu()
    : _currentScene(0)
{
    _scenes.push_back(std::make_unique<SelectionLib>());
}

void Arcade::Game::MainMenu::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    _scenes[_currentScene]->update(deltaTime, eventManager);
}

Arcade::ECS::IEntityManager &Arcade::Game::MainMenu::getCurrentEntityManager()
{
    return _scenes[_currentScene]->getEntityManager();
}
