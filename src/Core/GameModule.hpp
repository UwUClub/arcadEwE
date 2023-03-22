//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_GAMEMODULE_HPP
#define ARCADE_GAMEMODULE_HPP

#include "IGameModule.hpp"
#include "LibraryHandler.hpp"

namespace Arcade::Core
{
    class GameModule : public IGameModule
    {
        public:
            GameModule(const libList &libList);
            virtual ~GameModule() = default;

            Arcade::Game::ISceneManager &getSceneManager() override;
            void changeGame(const std::string &gameName) override;
            void changeGame() override;

            private:
            libList _libList;
            libInfo _currentGame;
            std::unique_ptr<Arcade::Game::ISceneManager> _sceneManager;
    };
}

#endif // ARCADE_GAMEMODULE_HPP
