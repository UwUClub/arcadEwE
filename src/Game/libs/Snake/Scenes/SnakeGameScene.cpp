/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameScene
*/

#include "SnakeGameScene.hpp"
#include "SystemManager.hpp"
#include "PlayerInputs.hpp"
#include "MoveSnake.hpp"
#include "ObjectFactory.hpp"
#include "CollsionManager.hpp"

namespace Snake {
    SnakeGameScene::SnakeGameScene() : SnakeScene()
    {
    }

    bool SnakeGameScene::init()
    {
        _systemManager->addSystem("PlayerInputs", std::make_unique<Snake::PlayerInputs>());
        _systemManager->addSystem("MoveSnake", std::make_unique<Snake::MoveSnake>());
        _systemManager->addSystem("FruitSpawner", std::make_unique<Snake::FruitSpawner>());
        _systemManager->addSystem("CollisionManager", std::make_unique<Snake::CollisionManager>());

        ObjectFactory objectFactory(_entityManager);
        objectFactory.CreateSnakeHead(Arcade::Vector3f(MAX_CASE_X / 2 * CASE_SIZE , MAX_CASE_X / 2 * CASE_SIZE, 0));
        objectFactory.CreateSnakeBody(Arcade::Vector3f(MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_X / 2 + 1) * CASE_SIZE, 0), Arcade::Vector3f(0, 0, 0));
        objectFactory.CreateSnakeBody(Arcade::Vector3f(MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_X / 2 + 2) * CASE_SIZE, 0), Arcade::Vector3f(0, 0, 0));
        objectFactory.CreateSnakeBody(Arcade::Vector3f(MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_X / 2 + 3) * CASE_SIZE, 0), Arcade::Vector3f(0, 0, 0));
        return true;
    }
}
