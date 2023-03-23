/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeEntry
*/

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "PlayerInputs.hpp"
#include "OnClickResume.hpp"

namespace Snake {
    std::unique_ptr<Arcade::Game::ISceneManager> createSnakeMenuScene()
    {
        auto sceneManager = std::make_unique<Arcade::Game::SceneManager>();
        auto systemManager = std::make_unique<Arcade::ECS::SystemManager>();
        auto entityManager = std::make_unique<Arcade::ECS::EntityManager>();

        systemManager->addSystem("onClickResume", new Snake::OnClickResume());
        auto snakeMenuScene = std::make_unique<Arcade::Game::Scene>(std::move(entityManager), std::move(systemManager));

        sceneManager->registerScene("snakeMenu", std::move(snakeMenuScene));
        return sceneManager;
    }

    std::unique_ptr<Arcade::Game::ISceneManager> createSnakeGameScene()
    {
        auto sceneManager = std::make_unique<Arcade::Game::SceneManager>();
        auto systemManager = std::make_unique<Arcade::ECS::SystemManager>();
        auto entityManager = std::make_unique<Arcade::ECS::EntityManager>();

        systemManager->addSystem("playerInputs", new Snake::PlayerInputs());
        auto snakeGameScene = std::make_unique<Arcade::Game::Scene>(std::move(entityManager), std::move(systemManager));

        sceneManager->registerScene("snakeGame", std::move(snakeGameScene));
        return sceneManager;
    }
}
