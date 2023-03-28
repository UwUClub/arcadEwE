/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeScene
*/

#ifndef SNAKESCENE_HPP_
    #define SNAKESCENE_HPP_
    #include "IEventManager.hpp"
    #include "IEntityManager.hpp"
    #include "ISystemManager.hpp"

namespace Snake
{
    class SnakeScene {
        public:
            SnakeScene();
            virtual ~SnakeScene() = default;

            void update(float deltaTime, Arcade::ECS::IEventManager &eventManager);
            Arcade::ECS::IEntityManager &getEntityManager();

        protected:
            std::unique_ptr<Arcade::ECS::IEntityManager> _entityManager;
            std::unique_ptr<Arcade::ECS::ISystemManager> _systemManager;
    };
} // namespace Snake

#endif /* !SNAKESCENE_HPP_ */
