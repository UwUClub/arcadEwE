/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameModule
*/

#ifndef Nibbler_GAME_MODULE_HPP_
#define Nibbler_GAME_MODULE_HPP_
#include "IComponent.hpp"
#include "IGameModule.hpp"
#include "NibblerScene.hpp"

namespace Nibbler
{
    class NibblerGameModule : public Arcade::Game::IGameModule
    {
        public:
        NibblerGameModule();
        ~NibblerGameModule() override = default;

        void update(double deltaTime, Arcade::ECS::IEventManager &eventManager) override;
        Arcade::ECS::IEntityManager &getCurrentEntityManager() override;

        private:
        void changeScene(std::size_t sceneId);
        void handleEventSceneChange(Arcade::ECS::IEventManager &eventManager);
        size_t _score = 0;

        private:
        std::size_t _currentScene;
        std::vector<std::unique_ptr<NibblerScene>> _scenes;

        private:
        class NibblerException : public std::exception
        {
            public:
            NibblerException(const std::string &message)
                : _message(message) {};
            ~NibblerException() override = default;

            const char *what() const noexcept override
            {
                return _message.c_str();
            }

            private:
            std::string _message;
        };
    };
} // namespace Nibbler

#endif /* !Nibbler_GAME_MODULE_HPP_ */
