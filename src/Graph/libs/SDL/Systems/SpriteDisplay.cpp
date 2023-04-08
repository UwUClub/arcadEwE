//
// Created by patatofour on 04/04/23.
//

#include <iostream>
#include "IComponent.hpp"
#include "SdlDisplayModule.hpp"
#include "SpriteDisplay.hpp"

SDL_Texture *Arcade::Graph::SpriteDisplay::loadTexture(const std::string &path,
    SDL_Renderer *renderer)
{
    SDL_Texture *texture = nullptr;

    if (_textures.find(path) != _textures.end()) {
        return _textures.at(path);
    }
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (texture == nullptr) {
        std::cerr << "Failed to load texture: " << path << std::endl;
        return nullptr;
    }
    _textures.emplace(path, texture);
    return texture;
}

void Arcade::Graph::SpriteDisplay::drawSprite(SDL_Renderer *renderer,
    const std::shared_ptr<ISprite> &sprite)
{
    SDL_Rect rect;
    SDL_Rect srcRect;
    SDL_Texture *texture = loadTexture(sprite->path, renderer);

    if (texture == nullptr)
        return;
    rect.x = sprite->rect.left;
    rect.y = sprite->rect.top;
    rect.w = sprite->rect.width;
    rect.h = sprite->rect.height;
    srcRect.x = (sprite->pos.x / 100) * SCREEN_WIDTH / 2;
    srcRect.y = (sprite->pos.y / 100) * SCREEN_HEIGHT;
    srcRect.w = sprite->rect.width;
    srcRect.h = sprite->rect.height;

    SDL_RenderCopy(renderer, texture, &rect, &srcRect);
}

Arcade::Graph::SpriteDisplay::~SpriteDisplay()
{
    for (auto &[key, value] : _textures) {
        SDL_DestroyTexture(value);
    }
}

void Arcade::Graph::SpriteDisplay::run([[maybe_unused]] double delta, SDL_Renderer *renderer,
    Arcade::ECS::IEntityManager &entityManager)
{
    auto sprites = entityManager.getEntitiesByComponentType(ECS::CompType::SPRITE);

    for (auto &sprite : *sprites) {
        auto &spriteComps = sprite->getComponents(ECS::CompType::SPRITE);

        for (auto &spriteComp : spriteComps) {
            auto castedSprite = std::static_pointer_cast<ISprite>(spriteComp);
            drawSprite(renderer, castedSprite);
        }
    }
}
