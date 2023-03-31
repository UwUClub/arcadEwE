//
// Created by patatofour on 28/03/23.
//

#pragma once

#include "IScene.hpp"

namespace Arcade::Game
{
    class AScene : public IScene
    {
        public:
        AScene();
        virtual ~AScene() = default;

        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager);
        Arcade::ECS::IEntityManager &getEntityManager() override;

        bool init() override = 0;
        void close() final;

        protected:
        class SceneException : public std::exception
        {
            public:
            SceneException(const std::string &message)
                : _message(message)
            {
            }

            ~SceneException() override = default;

            const char *what() const noexcept override
            {
                return _message.c_str();
            }

            private:
            std::string _message;
        };

        std::unique_ptr<Arcade::ECS::IEntityManager> _entityManager;
        std::unique_ptr<Arcade::ECS::ISystemManager> _systemManager;
    };
}
