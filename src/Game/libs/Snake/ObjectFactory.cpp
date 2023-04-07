/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ObjectFactory
*/

#include "ObjectFactory.hpp"
#include "SnakeGameScene.hpp"
#include "Transform.hpp"
#include "Direction.hpp"
#include "Speed.hpp"
#include "SnakeSprite.hpp"
#include "BoxCollider.hpp"
#include "SnakeHeadCollider.hpp"
#include "SnakePath.hpp"

namespace Snake
{
    ObjectFactory::ObjectFactory()
    {
    }

    ObjectFactory::~ObjectFactory()
    {
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateSnakeHead(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("snake_head");
        auto transform
            = std::shared_ptr<Snake::Transform>(new Snake::Transform("Transform", position));
        auto speed = std::shared_ptr<Snake::Speed>(new Snake::Speed("Speed", SPEED_ENTITY));

        speed->setNextPoint(
            { position.x / CASE_SIZE * CASE_SIZE, position.y / CASE_SIZE * CASE_SIZE, 0 });
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Snake::Direction>(
            new Snake::Direction("Direction", Direction::dir::UP)));
        entity.addComponent(speed);
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("Sprite", SNAKE_PATH,
            { "H", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, CASE_SIZE * 10, CASE_SIZE * 10 }, 0)));
        entity.addComponent(std::shared_ptr<Snake::SnakeHeadCollider>(new Snake::SnakeHeadCollider(
            "SnakeCollider", { CASE_SIZE / 2, CASE_SIZE / 2, 0 }, *transform)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateSnakeBody(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position, Arcade::Vector3f rotation)
    {
        auto entities = entityManager.getEntities();
        int snakeBodyCount = 0;

        for (auto &entity : entities) {
            std::string id = entity->getId();
            if (id.find("snake_body") != std::string::npos) {
                snakeBodyCount++;
            }
        }
        auto &entity = entityManager.createEntity("snake_body");
        (void) rotation;
        auto transform
            = std::shared_ptr<Snake::Transform>(new Snake::Transform("Transform", position));
        auto boxCollider = std::shared_ptr<Snake::BoxCollider>(
            new Snake::BoxCollider("BoxCollider", { CASE_SIZE / 2, CASE_SIZE / 2, 0 }, *transform));
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Snake::SnakePath>(new Snake::SnakePath("SnakePath")));
        entity.addComponent(std::shared_ptr<Snake::Direction>(
            new Snake::Direction("Direction", Direction::dir::UP)));
        entity.addComponent(std::shared_ptr<Snake::Speed>(new Snake::Speed("Speed", SPEED_ENTITY)));
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("Sprite", SNAKE_PATH,
            { "B", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, CASE_SIZE * 10, CASE_SIZE * 10 }, 0)));
        entity.addComponent(boxCollider);
        if (snakeBodyCount == 0) {
            boxCollider->isEnabled = false;
        }
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateFruit(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("fruit");
        auto transform
            = std::shared_ptr<Snake::Transform>(new Snake::Transform("Transform", position));
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("sprite", FRUIT_PATH,
            { "F", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, CASE_SIZE * 10, CASE_SIZE * 10 }, 0)));
        entity.addComponent(std::shared_ptr<Snake::BoxCollider>(
            new Snake::BoxCollider("BoxCollider", { CASE_SIZE, CASE_SIZE, 0 }, *transform)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateWall(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position, Arcade::Vector3f rotation)
    {
        auto &entity = entityManager.createEntity("wall");
        (void) rotation;
        auto transform
            = std::shared_ptr<Snake::Transform>(new Snake::Transform("Transform", position));
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("sprite", WALL_PATH,
            { "#", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, CASE_SIZE, CASE_SIZE }, 0)));
        entity.addComponent(std::shared_ptr<Snake::BoxCollider>(new Snake::BoxCollider(
            "BoxCollider", { CASE_SIZE / 2, CASE_SIZE / 2, 0 }, *transform)));
        return entity;
    }
} // namespace Snake
