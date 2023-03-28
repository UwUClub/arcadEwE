//
// Created by patatofour on 28/03/23.
//

#include "MainMenu.hpp"
#include "SelectionLib.hpp"
#include "Events.hpp"

Arcade::Game::MainMenu::MainMenu()
    : _currentScene(0)
{
    _scenes.push_back(std::make_unique<SelectionLib>());
}

void Arcade::Game::MainMenu::update(float deltaTime, Arcade::ECS::IEventManager &eventManager)
{
    handleEventSceneChange(eventManager);
    _scenes[_currentScene]->update(deltaTime, eventManager);
}

Arcade::ECS::IEntityManager &Arcade::Game::MainMenu::getCurrentEntityManager()
{
    return _scenes[_currentScene]->getEntityManager();
}

void Arcade::Game::MainMenu::changeScene(std::size_t sceneId)
{
    if (sceneId >= _scenes.size())
        throw MainMenuException("Scene does not exist");
    _scenes[_currentScene]->close();
    _currentScene = sceneId;
    _scenes[_currentScene]->init();
}

void Arcade::Game::MainMenu::handleEventSceneChange(Arcade::ECS::IEventManager &eventManager)
{
    auto key1 = eventManager.isEventTriggered(KEY_1_PRESSED);
    auto key2 = eventManager.isEventTriggered(KEY_2_PRESSED);

    if (key1.first && _currentScene == 1)
        changeScene(0);
    if (key2.first && _currentScene == 0)
        changeScene(1);
}
