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
    #define SNAKE_PATH "assets/images/SnakeSpriteSheet.png"
    #define FRUIT_PATH "assets/images/apple.png"
    #define WALL_PATH "assets/images/SnakeSpriteSheet.png"
    #define SPEED 10.0f

namespace Snake {
    class ObjectFactory {
        public:
            ObjectFactory();
            ~ObjectFactory();

            Arcade::ECS::IEntity &CreateSnakeHead(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position);
            Arcade::ECS::IEntity &CreateSnakeBody(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position, Arcade::Vector3f rotation);
            Arcade::ECS::IEntity &CreateFruit(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position);
            Arcade::ECS::IEntity &CreateWall(Arcade::ECS::IEntityManager &entityManager, Arcade::Vector3f position, Arcade::Vector3f rotation);
    };
}

#endif /* !OBJECTFACTORY_HPP_ */
