//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_MAINMENUSCENE_HPP
#define ARCADE_MAINMENUSCENE_HPP

#include "IEventManager.hpp"
#include "IEntityManager.hpp"
#include "ISystemManager.hpp"

namespace Arcade::Game
{
    class MainMenuScene
    {
        public:
        MainMenuScene();
        ~MainMenuScene() = default;

        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager);
        Arcade::ECS::IEntityManager &getEntityManager();

        protected:
        std::unique_ptr<Arcade::ECS::IEntityManager> _entityManager;
        std::unique_ptr<Arcade::ECS::ISystemManager> _systemManager;
    };
} // namespace Arcade::Game

#endif // ARCADE_MAINMENUSCENE_HPP
