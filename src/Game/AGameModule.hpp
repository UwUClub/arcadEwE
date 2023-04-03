//
// Created by patatofour on 28/03/23.
//

#pragma once

#include "IGameModule.hpp"
#include "AScene.hpp"

namespace Arcade::Game
{
    class AGameModule : public IGameModule
    {
        public:
        AGameModule();
        ~AGameModule() override = default;

        void update(double deltaTime, Arcade::ECS::IEventManager &eventManager) override;
        Arcade::ECS::IEntityManager &getCurrentEntityManager() override;

        protected:
        class AGameModuleException : public std::exception
        {
            public:
            AGameModuleException(const std::string &message)
                : _message(message)
            {
            }

            ~AGameModuleException() override = default;

            const char *what() const noexcept override
            {
                return _message.c_str();
            }

            private:
            std::string _message;
        };

        void changeScene(std::size_t sceneId);
        virtual void handleEventSceneChange(Arcade::ECS::IEventManager &eventManager) = 0;
        std::size_t _currentScene;
        std::vector<std::unique_ptr<AScene>> _scenes;
    };
} // namespace Arcade::Game
