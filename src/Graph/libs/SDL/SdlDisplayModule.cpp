//
// Created by patatofour on 31/03/23.
//

#include <SDL.h>
#include "SdlDisplayModule.hpp"
#include "Events.hpp"

Arcade::Graph::SDLDisplayModule::SDLDisplayModule()
    : _onEvent(std::make_unique<OnEvent>())
    , _renderer(nullptr)
    , _window(nullptr)
{
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return;
    }

    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!_window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        return;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

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
    SDL_RenderPresent(_renderer);
    SDL_Delay(16);
}

void Arcade::Graph::SDLDisplayModule::prepareScene(
    [[maybe_unused]] Arcade::ECS::IEntityManager &entityManager)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}
