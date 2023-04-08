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
#define NIBBLER_PATH   "assets/images/nibbler_body.png"
#define FRUIT_PATH   "assets/images/apple.png"
#define WALL_PATH    "assets/images/nibbler_body.png"
#define SPEED_ENTITY 30.0f

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
        Arcade::ECS::IEntity &CreateWall(Arcade::ECS::IEntityManager &entityManager,
            Arcade::Vector3f position, Arcade::Vector3f rotation);
    };
} // namespace Nibbler

#endif /* !OBJECTFACTORY_HPP_ */
