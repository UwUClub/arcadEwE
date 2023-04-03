//
// Created by patatofour on 28/03/23.
//

#include <iostream>
#include "MainMenu.hpp"
#include "SelectionLib.hpp"
#include "SaveReader.hpp"
#include "Events.hpp"

namespace Arcade::Game
{
    MainMenu::MainMenu()
        : AGameModule()
    {
        this->_currentScene = 0;

        this->_scenes.push_back(std::make_unique<SelectionLib>());
        this->_scenes.push_back(std::make_unique<SaveReader>());

        this->_scenes[this->_currentScene]->init();
    }

    void MainMenu::update([[maybe_unused]] double deltaTime,
        Arcade::ECS::IEventManager &eventManager)
    {
        AGameModule::update(deltaTime, eventManager);
        handleEventSceneChange(eventManager);
    }

    void MainMenu::handleEventSceneChange(Arcade::ECS::IEventManager &eventManager)
    {
        auto key1 = eventManager.isEventTriggered(KEY_1_PRESSED);
        auto key2 = eventManager.isEventTriggered(KEY_2_PRESSED);

        if (key1.first && _currentScene == 1)
            changeScene(0);
        if (key2.first && _currentScene == 0)
            changeScene(1);
    }
} // namespace Arcade::Game
