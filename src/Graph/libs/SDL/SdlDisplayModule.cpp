//
// Created by patatofour on 31/03/23.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_mixer.h>
#include "SdlDisplayModule.hpp"

Arcade::Graph::SDLDisplayModule::SDLDisplayModule()
    : _onEvent(std::make_unique<OnEvent>())
    , _soundHandler(std::make_unique<SoundHandler>())
    , _spriteDisplay(std::make_unique<SpriteDisplay>())
    , _textHandler(std::make_unique<TextHandler>())
    , _renderer(nullptr)
    , _window(nullptr)
{
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return;
    }

    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!_window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        return;
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Couldn't initialize SDL Mixer\n");
        return;
    }

    Mix_AllocateChannels(MAX_SND_CHANNELS);

    _renderer = SDL_CreateRenderer(_window, -1, rendererFlags);

    if (!_renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        return;
    }
}

Arcade::Graph::SDLDisplayModule::~SDLDisplayModule()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Arcade::Graph::SDLDisplayModule::update([[maybe_unused]] double delta,
    Arcade::ECS::IEventManager &eventManager, Arcade::ECS::IEntityManager &entityManager)
{
    SDL_Event event;

    prepareScene(entityManager);
    while (SDL_PollEvent(&event)) {
        _onEvent->run(eventManager, event);
    }
    _spriteDisplay->run(delta, _renderer, entityManager);
    _soundHandler->run(entityManager);
    _textHandler->run(_renderer, entityManager);
    SDL_RenderPresent(_renderer);
}

void Arcade::Graph::SDLDisplayModule::prepareScene(
    [[maybe_unused]] Arcade::ECS::IEntityManager &entityManager)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}
