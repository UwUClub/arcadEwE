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

namespace Snake {
    void SnakeEntry() {
        Arcade::Game::SceneManager sceneManager;
        Arcade::Game::Scene snakeScene(std::make_unique<Arcade::ECS::EntityManager>(),
            std::make_unique<Arcade::ECS::SystemManager>());
        Arcade::Game::Scene menuScene(std::make_unique<Arcade::ECS::EntityManager>(),
            std::make_unique<Arcade::ECS::SystemManager>());

        menuScene.getSystemManager().addSystem(std::make_unique<Snake::MenuSystem>());

        menuScene.getEntityManager().createEntity(std::make_unique<Snake::playButton>());

        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::MovementSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::RenderSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::InputSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::CollisionSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::ScoreSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::FoodSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::GameOverSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::SnakeSystem>());
        snakeScene.getSystemManager().addSystem(std::make_unique<Snake::WallSystem>());

        snakeScene.getEntityManager().createEntity(std::make_unique<Snake::SnakeEntity>());
        snakeScene.getEntityManager().createEntity(std::make_unique<Snake::FoodEntity>());
        snakeScene.getEntityManager().createEntity(std::make_unique<Snake::WallEntity>());
        snakeScene.getEntityManager().createEntity(std::make_unique<Snake::ScoreEntity>());

        sceneManager.registerScene("Menu", std::make_unique<Arcade::Game::Scene>(snakeScene));
        sceneManager.registerScene("Snake", std::make_unique<Arcade::Game::Scene>(snakeScene));
    }
}
