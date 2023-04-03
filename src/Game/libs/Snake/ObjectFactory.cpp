/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ObjectFactory
*/

#include "ObjectFactory.hpp"
#include "Transform.hpp"
#include "Direction.hpp"
#include "Speed.hpp"
#include "Sprite.hpp"

namespace Snake {
    ObjectFactory::ObjectFactory()
    {
    }

    ObjectFactory::~ObjectFactory()
    {
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateSnakeHead(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("snake_head");
        entity.addComponent(std::shared_ptr<Snake::Transform>(new Snake::Transform("Transform", position)));
        entity.addComponent(std::shared_ptr<Snake::Direction>(new Snake::Direction("Direction", Direction::dir::UP)));
        entity.addComponent(std::shared_ptr<Snake::Speed>(new Snake::Speed("Speed", 0.1f)));
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("Sprite", SNAKE_PATH, {"#", {255, 255, 255, 255}, {0, 0, 0, 255}}, position, {0, 0, 1, 1}, 0)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateSnakeBody(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position, Arcade::Vector3f rotation)
    {
        auto &entity = entityManager.createEntity("snake_body");
        (void)rotation;
        entity.addComponent(std::shared_ptr<Snake::Transform>(new Snake::Transform("Transform", position)));
        entity.addComponent(std::shared_ptr<Snake::Direction>(new Snake::Direction("Direction", Direction::dir::UP)));
        entity.addComponent(std::shared_ptr<Snake::Speed>(new Snake::Speed("Speed", 0.1f)));
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("Sprite", SNAKE_PATH, {"#", {255, 255, 255, 255}, {0, 0, 0, 255}}, position, {0, 0, 1, 1}, 0)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateFruit(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("fruit");
        entity.addComponent(std::shared_ptr<Snake::Transform>(new Snake::Transform("transform", position)));
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("sprite", FRUIT_PATH, {"#", {255, 255, 255, 255}, {0, 0, 0, 255}}, position, {0, 0, 1, 1}, 0)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateWall(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position, Arcade::Vector3f rotation)
    {
        auto &entity = entityManager.createEntity("wall");
        (void)rotation;
        entity.addComponent(std::shared_ptr<Snake::Transform>(new Snake::Transform("transform", position)));
        entity.addComponent(std::shared_ptr<Snake::Sprite>(new Snake::Sprite("sprite", WALL_PATH, {"#", {255, 255, 255, 255}, {0, 0, 0, 255}}, position, {0, 0, 1, 1}, 0)));
        return entity;
    }
}
