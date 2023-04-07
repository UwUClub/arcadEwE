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
#include "MoveTail.hpp"
#include "ObjectFactory.hpp"
#include "ColliderManager.hpp"
#include "FruitSpawner.hpp"
#include "ColliderManager.hpp"
#include "ArcadeStruct.hpp"
#include "TransformDisplay.hpp"
#include "SnakeGameManager.hpp"
#include "SnakeTailManager.hpp"

namespace Snake {
    SnakeGameScene::SnakeGameScene() : SnakeScene()
    {
    }

    bool SnakeGameScene::init()
    {
        ObjectFactory objectFactory;

        if (_entityManager == nullptr)
            _entityManager = std::make_unique<Arcade::ECS::EntityManager>();
        if (_systemManager == nullptr)
            _systemManager = std::make_unique<Arcade::ECS::SystemManager>();

        _systemManager->addSystem("PlayerInputs", std::make_unique<Snake::PlayerInputs>());
        _systemManager->addSystem("MoveSnake", std::make_unique<Snake::MoveSnake>());
        _systemManager->addSystem("FruitSpawner", std::make_unique<Snake::FruitSpawner>());
        _systemManager->addSystem("TransformDisplay", std::make_unique<Snake::TransformDisplay>());
        _systemManager->addSystem("SnakeGameManager", std::make_unique<Snake::SnakeGameManager>());
        _systemManager->addSystem("ColliderManager", std::make_unique<Snake::ColliderManager>());
        _systemManager->addSystem("MoveTail", std::make_unique<Snake::MoveTail>());
        _systemManager->addSystem("SnakeTailManager", std::make_unique<Snake::SnakeTailManager>());

        objectFactory.CreateSnakeHead(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE , MAX_CASE_Y / 2 * CASE_SIZE, 0});
        objectFactory.CreateSnakeBody(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_Y / 2 + 1) * CASE_SIZE, 0}, {0, 0, 0});
        objectFactory.CreateSnakeBody(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_Y / 2 + 2) * CASE_SIZE, 0}, {0, 0, 0});
        objectFactory.CreateSnakeBody(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_Y / 2 + 3) * CASE_SIZE, 0}, {0, 0, 0});
        return true;
    }
}
