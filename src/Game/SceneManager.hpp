//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_SCENEMANAGER_HPP
#define ARCADE_SCENEMANAGER_HPP

#include "ISceneManager.hpp"

namespace Arcade::Game
{
    class SceneManager : public ISceneManager
    {
        public:
        SceneManager();
        ~SceneManager() override = default;

        void registerScene(const std::string &sceneName,
            std::unique_ptr<IScene> scene) override;
        std::unique_ptr<IScene> &getCurrentScene() override;
        void changeScene(const std::string &sceneName) override;

        protected:
        std::map<std::string, std::unique_ptr<IScene>> _scenes;
        std::string _currentSceneName;
    };
} // namespace Arcade::Game

#endif // ARCADE_SCENEMANAGER_HPP
