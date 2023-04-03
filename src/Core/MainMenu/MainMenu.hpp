//
// Created by patatofour on 28/03/23.
//

#ifndef ARCADE_MAINMENU_HPP
#define ARCADE_MAINMENU_HPP

#include "AGameModule.hpp"

namespace Arcade::Game
{
    class MainMenu : public AGameModule
    {
        public:
        MainMenu();
        ~MainMenu() override = default;

        void update(double deltaTime, Arcade::ECS::IEventManager &eventManager) override;

        private:
        void handleEventSceneChange(Arcade::ECS::IEventManager &eventManager) override;
    };
} // namespace Arcade::Game

#endif // ARCADE_MAINMENU_HPP
