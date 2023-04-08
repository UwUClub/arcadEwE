/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ObjectFactory
*/

#ifndef OBJECTFACTORY_HPP_
#define OBJECTFACTORY_HPP_
#include "IEntityManager.hpp"
#include "ArcadeStruct.hpp"
#define SNAKE_HEAD_PATH   "assets/images/snake_head.png"
#define SNAKE_HEAD_SIZE 64
#define SNAKE_BODY_PATH   "assets/images/snake_body.png"
#define SNAKE_BODY_SIZE 64
#define FRUIT_PATH   "assets/images/apple.png"
#define FRUIT_SIZE 128
#define WALL_PATH    "assets/images/snake_body.png"
#define SPEED_ENTITY 30.0f

namespace Snake
{
    class ObjectFactory
    {
        public:
        ObjectFactory();
        ~ObjectFactory();

        Arcade::ECS::IEntity &CreateSnakeHead(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position);
        Arcade::ECS::IEntity &CreateSnakeBody(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position, Arcade::Vector3f rotation);
        Arcade::ECS::IEntity &CreateFruit(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position);
        Arcade::ECS::IEntity &CreateWall(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position, Arcade::Vector3f rotation);
    };
} // namespace Snake

#endif /* !OBJECTFACTORY_HPP_ */
