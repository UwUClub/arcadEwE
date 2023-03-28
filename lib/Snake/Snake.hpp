/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
    #include "IComponent.hpp"
    #include "IGameModule.hpp"
    #include "SnakeMenuScene.hpp"

enum class Arcade::ECS::CompType: int {
    TEXT = 0,
    SPRITE = 1,
    MUSIC = 2,
    MOVEMENTS = 3
};

namespace Snake {
    class Snake : public Arcade::Game::IGameModule
    {
        public:
            Snake();
            ~Snake() override = default;

            void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) override;
            Arcade::ECS::IEntityManager &getCurrentEntityManager() override;
        protected:
        private:
            std::size_t _currentScene;
            std::vector<std::unique_ptr<SnakeMenuScene>> _scenes;
    };
}

#endif /* !SNAKE_HPP_ */
