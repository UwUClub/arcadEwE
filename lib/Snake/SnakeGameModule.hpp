/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakeGameModule
*/

#ifndef SNAKE_GAME_MODULE_HPP_
    #define SNAKE_GAME_MODULE_HPP_
    #include "IComponent.hpp"
    #include "IGameModule.hpp"
    #include "SnakeScene.hpp"

namespace Snake {
    class SnakeGameModule : public Arcade::Game::IGameModule
    {
        public:
            SnakeGameModule();
            ~SnakeGameModule() override = default;

            void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) override;
                Arcade::ECS::IEntityManager &getCurrentEntityManager() override;

        private:
            void changeScene(std::size_t sceneId);
            void handleEventSceneChange(Arcade::ECS::IEventManager &eventManager);

        private:
            std::size_t _currentScene;
            std::vector<std::unique_ptr<SnakeScene>> _scenes;

        private:
            class SnakeException : public std::exception
            {
                public:
                    SnakeException(const std::string &message) : _message(message){};
                    ~SnakeException() override = default;

                    const char *what() const noexcept override
                    {
                        return _message.c_str();
                    }

                private:
                    std::string _message;
            };
    };
}

#endif /* !SNAKE_GAME_MODULE_HPP_ */