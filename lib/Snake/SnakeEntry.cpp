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
#include "Movements.hpp"
#include "TextHitbox.hpp"
#include "Text.hpp"

namespace Snake {
    std::unique_ptr<Arcade::Game::ISceneManager> createSnakeMenuScene()
    {
        auto sceneManager = std::make_unique<Arcade::Game::SceneManager>();
        auto systemManager = std::make_unique<Arcade::ECS::SystemManager>();
        auto entityManager = std::make_unique<Arcade::ECS::EntityManager>();

        systemManager->addSystem("onClickResume", new Snake::OnClickResume());

        auto &entity = entityManager->createEntity("resume_button");

        Vector2f pos = { 0, 0 }; // todo
        Vector2f box = { lib.second.length() * FONT_SIZE * AVERAGE_CHAR_SIZE, FONT_SIZE * 2 }; // todo
        Graph::Color white = { 255, 255, 255, 255 };
        Graph::Color black = { 0, 0, 0, 255 };

        auto textComp = std::shared_ptr<Arcade::ECS::IComponent>(new Arcade::Graph::Text("0", lib.second, black, white, pos));
        auto hitboxComp = std::shared_ptr<Arcade::ECS::IComponent>(new Arcade::Core::TextHitbox("1", box));
        entity.addComponent(textComp);
        entity.addComponent(hitboxComp);

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

        auto &entity = entityManager->createEntity("snake_head");
        entity.addComponent(std::shared_ptr<Arcade::ECS::IComponent>(new Arcade::ECS::Position("0", {0, 0})));
        entity.addComponent(std::shared_ptr<Arcade::ECS::IComponent>(new Snake::Movements("1", Snake::Movements::Direction::UP)));

        auto snakeGameScene = std::make_unique<Arcade::Game::Scene>(std::move(entityManager), std::move(systemManager));
        sceneManager->registerScene("snakeGame", std::move(snakeGameScene));
        return sceneManager;
    }
}
