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
#define NIBBLER_HEAD_PATH    "assets/snake/lego/head.png"
#define NIBBLER_BODY_PATH    "assets/snake/lego/bg_green.png"
#define NIBBLER_SIZE         64
#define FRUIT_PATH           "assets/snake/lego/apple.png"
#define FRUIT_SIZE           64
#define HORIZONTAL_WALL_PATH "assets/images/horizontal_wall.png"
#define VERTICAL_WALL_PATH   "assets/images/vertical_wall.png"
#define WALL_WIDTH           21
#define WALL_HEIGHT          108
#define SPEED_ENTITY         10.0f

namespace Nibbler
{
    class ObjectFactory
    {
        public:
        ObjectFactory();
        ~ObjectFactory();

        Arcade::ECS::IEntity &CreateNibblerHead(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position);
        Arcade::ECS::IEntity &CreateNibblerBody(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position, Arcade::Vector3f rotation);
        Arcade::ECS::IEntity &CreateFruit(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position);
        Arcade::ECS::IEntity &CreateHorizontalWall(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position);
        Arcade::ECS::IEntity &CreateVerticalWall(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position);
    };
} // namespace Nibbler

#endif /* !OBJECTFACTORY_HPP_ */
