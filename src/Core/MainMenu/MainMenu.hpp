//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include "IGameModule.hpp"
#include "MainMenuScene.hpp"

namespace Arcade::Game
{
    class MainMenu : public IGameModule
    {
        public:
        MainMenu();
        ~MainMenu() override = default;

        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager) override;
        Arcade::ECS::IEntityManager &getCurrentEntityManager() override;

        private:
        class MainMenuException : public std::exception
        {
            public:
            MainMenuException(const std::string &message)
                : _message(message)
            {
            }

            ~MainMenuException() override = default;

            const char *what() const noexcept override
            {
                return _message.c_str();
            }

            private:
            std::string _message;
        };

        void changeScene(std::size_t sceneId);
        void handleEventSceneChange(Arcade::ECS::IEventManager &eventManager);
        std::size_t _currentScene;
        std::vector<std::unique_ptr<MainMenuScene>> _scenes;
    };
} // namespace Arcade::Game

#endif // ARCADE_MAINMENU_HPP
