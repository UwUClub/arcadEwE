//
// Created by patatofour on 31/03/23.
//

#ifndef ARCADE_SDLDISPLAYMODULE_HPP
#define ARCADE_SDLDISPLAYMODULE_HPP

#include <memory>
#include "IDisplayModule.hpp"
#include "OnEvent.hpp"
#include "SoundHandler.hpp"
#include "SpriteDisplay.hpp"
#include "TextHandler.hpp"

#define SCREEN_WIDTH     1920
#define SCREEN_HEIGHT    1080
#define MAX_SND_CHANNELS 16

namespace Arcade::Graph
{
    class SDLDisplayModule : public IDisplayModule
    {
        public:
        SDLDisplayModule();
        ~SDLDisplayModule() override;

        void update(double delta, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager) override;

        private:
        void prepareScene(Arcade::ECS::IEntityManager &entityManager);
        std::unique_ptr<OnEvent> _onEvent;
        std::unique_ptr<SoundHandler> _soundHandler;
        std::unique_ptr<SpriteDisplay> _spriteDisplay;
        std::unique_ptr<TextHandler> _textHandler;
        SDL_Renderer *_renderer;
        SDL_Window *_window;
    };
} // namespace Arcade::Graph

#endif // ARCADE_SDLDISPLAYMODULE_HPP
