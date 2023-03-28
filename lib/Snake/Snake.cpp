/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Snake
*/

#include "Snake.hpp"

namespace Snake {
    Snake::Snake()
    {
        _currentScene = 0;
        _scenes.emplace_back(std::make_unique<MainMenuScene>());
    }

    void Snake::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
    {
        _scenes[_currentScene]->update(deltaTime, eventManager);
    }

    Arcade::ECS::IEntityManager &Snake::getCurrentEntityManager()
    {
        return _scenes[_currentScene]->getCurrentEntityManager();
    }
} // namespace Snake
