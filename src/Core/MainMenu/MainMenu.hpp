//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include "IGameModule.hpp"
#include "Core/MainMenu/Scene/MainMenuScene.hpp"

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
        std::size_t _currentScene;
        std::vector<std::unique_ptr<MainMenuScene>> _scenes;
    };
} // namespace Arcade::Game

#endif // ARCADE_MAINMENU_HPP
