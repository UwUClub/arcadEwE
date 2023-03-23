//
// Created by valegox on 23/03/23.
//

#pragma once

#include "ISystem.hpp"
#include "IScene.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace Arcade::Graph {
    class SFMLSystem : public Arcade::ECS::ISystem
    {
        public:
        SFMLSystem();
        ~SFMLSystem() override;

        void run(std::size_t deltaTime, Arcade::ECS::IEventManager &,
            Arcade::Core::IDisplayModule &displayModule,
            Arcade::Core::IGameModule &gameModule) override;
        
        void drawSprites(std::unique_ptr<Arcade::Game::IScene> &scene);
        void drawTexts(std::unique_ptr<Arcade::Game::IScene> &scene);
        void handleMusics(std::unique_ptr<Arcade::Game::IScene> &scene);
        void captureEvents(Arcade::ECS::IEventManager &eventManager);

        protected:
        sf::RenderWindow _window;
        std::map<std::string, sf::Music *> _playingMusics; // key is music id
    };
}
