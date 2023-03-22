//
// Created by patatofour on 21/03/23.
//

#include "SceneManager.hpp"

namespace Arcade::Game
{
    void SceneManager::registerScene(const std::string &sceneName,
        std::unique_ptr<IScene> scene)
    {
        _scenes[sceneName] = std::move(scene);
    }

    std::unique_ptr<IScene> &SceneManager::getCurrentScene()
    {
        return _scenes[_currentSceneName];
    }

    void SceneManager::changeScene(const std::string &sceneName)
    {
        _currentSceneName = sceneName;
    }
} // namespace Arcade::Game
