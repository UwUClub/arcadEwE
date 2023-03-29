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
#include "Position.hpp"
#include "Direction.hpp"
#include "Speed.hpp"
#include "Sprite.hpp"

namespace Snake {
    SnakeGameScene::SnakeGameScene() : SnakeScene()
    {
    }

    bool SnakeGameScene::init()
    {
        _systemManager->addSystem("PlayerInputs", std::make_unique<Snake::PlayerInputs>());
        _systemManager->addSystem("MoveSnake", std::make_unique<Snake::MoveSnake>());

        auto &entity = _entityManager->createEntity("snake_head");
        entity.addComponent(std::shared_ptr<Snake::Position>(new Snake::Position("position", Arcade::Vector3f(50, 50, 0))));
        entity.addComponent(std::shared_ptr<Snake::Direction>(new Snake::Direction("direction", Direction::dir::UP)));
        entity.addComponent(std::shared_ptr<Snake::Speed>(new Snake::Speed("speed", 0.1f)));
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("sprite", SNAKE_PATH, {"#", {255, 255, 255, 255}, {0, 0, 0, 255}}, Arcade::Vector3f(50, 50, 0), {0, 0, 1, 1}, 0)));
        return true;
    }
}
