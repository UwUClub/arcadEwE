/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerScene
*/

#ifndef SNAKESCENE_HPP_
#define SNAKESCENE_HPP_
#include "IEventManager.hpp"
#include "IEntityManager.hpp"
#include "EntityManager.hpp"
#include "ISystemManager.hpp"
#include "IScene.hpp"

namespace Nibbler
{
    class NibblerScene : public Arcade::Game::IScene
    {
        public:
        NibblerScene();
        virtual ~NibblerScene() = default;

        void update(float deltaTime, Arcade::ECS::IEventManager &eventManager);
        Arcade::ECS::IEntityManager &getEntityManager();

        bool init() override = 0;
        void close() final;

        protected:
        std::unique_ptr<Arcade::ECS::IEntityManager> _entityManager;
        std::unique_ptr<Arcade::ECS::ISystemManager> _systemManager;
    };
} // namespace Nibbler

#endif /* !SNAKESCENE_HPP_ */
