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
    }

    void SnakeGameModule::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
    {
        _scenes[_currentScene]->update(deltaTime, eventManager);
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

        if (play.first && _currentScene == 0)
            changeScene(1);
        if (gameOver.first && _currentScene == 1)
            changeScene(0);
    }

} // namespace Snake
