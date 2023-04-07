/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameModule
*/

#include "SnakeGameModule.hpp"
#include "SnakeGameScene.hpp"
#include "SnakeMenuScene.hpp"
#include "EventManager.hpp"

namespace Snake {
    SnakeGameModule::SnakeGameModule()
    {
        _currentScene = 0;
        _scenes.emplace_back(std::make_unique<SnakeMenuScene>());
        _scenes.emplace_back(std::make_unique<SnakeGameScene>());
        _scenes[_currentScene]->init();
    }

    void SnakeGameModule::update(double deltaTime, Arcade::ECS::IEventManager &eventManager)
    {
        _scenes[_currentScene]->update(deltaTime, eventManager);
        handleEventSceneChange(eventManager);
    }

    Arcade::ECS::IEntityManager &SnakeGameModule::getCurrentEntityManager()
    {
        return _scenes[_currentScene]->getEntityManager();
    }

    void SnakeGameModule::changeScene(std::size_t sceneId)
    {
        if (sceneId >= _scenes.size())
            throw SnakeException("Scene does not exist");
        _scenes[_currentScene]->close();
        _currentScene = sceneId;
        _scenes[_currentScene]->init();
    }

    void SnakeGameModule::handleEventSceneChange(Arcade::ECS::IEventManager &eventManager)
    {
        auto play = eventManager.isEventTriggered("PLAY");
        auto gameOver = eventManager.isEventTriggered("GAME_OVER");
        auto rPressed = eventManager.isEventTriggered("KEY_R_PRESSED");
        auto tPressed = eventManager.isEventTriggered("KEY_T_PRESSED");

        if (play.first && _currentScene == 0)
            changeScene(1);
        if (gameOver.first && _currentScene == 1)
            changeScene(0);
        if (rPressed.first)
            changeScene(1);
        if (tPressed.first && _currentScene != 0)
            changeScene(0);
    }

} // namespace Snake
