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
    #define FRUIT_PATH "assets/images/SnakeSpriteSheet.png"
    #define WALL_PATH "assets/images/SnakeSpriteSheet.png"

namespace Snake {
    class ObjectFactory {
        public:
            ObjectFactory(std::unique_ptr<Arcade::ECS::IEntityManager> entityManager);
            ~ObjectFactory();

            Arcade::ECS::IEntity &CreateSnakeHead(Arcade::Vector3f position);
            Arcade::ECS::IEntity &CreateSnakeBody(Arcade::Vector3f position, Arcade::Vector3f rotation);
            Arcade::ECS::IEntity &CreateFruit(Arcade::Vector3f position);
            Arcade::ECS::IEntity &CreateWall(Arcade::Vector3f position, Arcade::Vector3f rotation);

        private:
            std::unique_ptr<Arcade::ECS::IEntityManager> _entityManager;
    };
}

#endif /* !OBJECTFACTORY_HPP_ */
