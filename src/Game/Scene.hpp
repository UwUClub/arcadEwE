//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_SCENE_HPP
#define ARCADE_SCENE_HPP

#include <memory>
#include "IScene.hpp"

namespace Arcade::Game
{
    class Scene : public IScene
    {
        public:
            Scene(std::unique_ptr<ECS::IEntityManager> entityManager,
                std::unique_ptr<ECS::ISystemManager> systemManager);
            ~Scene() override = default;

            bool init() override { return true; };
            void close() override {};

            ECS::IEntityManager &getEntityManager() final;
            ECS::ISystemManager &getSystemManager() final;

        protected:
            std::unique_ptr<ECS::IEntityManager> _entityManager;
            std::unique_ptr<ECS::ISystemManager> _systemManager;
    };
} // namespace Arcade::Game

#endif // ARCADE_SCENE_HPP
