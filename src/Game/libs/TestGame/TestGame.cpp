/*
** EPITECH PROJECT, 2023
** Archi Arcade Promo 2026 Toulouse
** File description:
** Test - Game module
*/

#include "TestGame.hpp"
#include "MainScene.hpp"

namespace Arcade::Game
{

    TestGame::TestGame()
        : AGameModule()
    {
        this->_currentScene = 0;

        this->_scenes.push_back(std::make_unique<MainScene>());

        this->_scenes[this->_currentScene]->init();
    }

    void TestGame::update([[maybe_unused]] float delta,
        [[maybe_unused]] Arcade::ECS::IEventManager &eventManager)
    {
        AGameModule::update(delta, eventManager);
    }

    void TestGame::handleEventSceneChange([[maybe_unused]] Arcade::ECS::IEventManager &eventManager)
    {
    }
} // namespace Arcade::Game
