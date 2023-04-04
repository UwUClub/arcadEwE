//
// Created by patatofour on 04/04/23.
//

#include <iostream>
#include "TextHandler.hpp"
#include "SdlDisplayModule.hpp"

namespace Arcade::Graph
{
    TextHandler::TextHandler()
    {
        TTF_Init();

        loadFont("assets/fonts/arial.ttf");
    }

    TextHandler::~TextHandler()
    {
        for (auto &font : _fonts) {
            if (font.second != nullptr)
                TTF_CloseFont(font.second);
        }
        TTF_Quit();
    }

    TTF_Font *TextHandler::loadFont(const std::string &path)
    {
        TTF_Font *font = nullptr;

        if (_fonts.find(path) != _fonts.end())
            return _fonts.at(path);
        font = TTF_OpenFont(path.c_str(), 20);
        if (font == nullptr) {
            if (_fonts.find("assets/fonts/arial.ttf") != _fonts.end())
                return _fonts.at("assets/fonts/arial.ttf");
            return nullptr;
        }
        _fonts.emplace(path, font);
        return font;
    }

    void TextHandler::run(SDL_Renderer *renderer, Arcade::ECS::IEntityManager &entityManager)
    {
        auto texts = entityManager.getEntitiesByComponentType(ECS::CompType::TEXT);

        for (auto &text : *texts) {
            auto &textComps = text->getComponents(ECS::CompType::TEXT);

            for (auto &textComp : textComps) {
                drawText(renderer, std::dynamic_pointer_cast<IText>(textComp));
            }
        }
    }

    void TextHandler::drawText(SDL_Renderer *renderer, const std::shared_ptr<IText> &text)
    {
        SDL_Color textColor
            = { static_cast<Uint8>(text->textColor.r), static_cast<Uint8>(text->textColor.g),
                  static_cast<Uint8>(text->textColor.b), static_cast<Uint8>(text->textColor.a) };
        SDL_Color backgroundColor = { static_cast<Uint8>(text->backgroundColor.r),
            static_cast<Uint8>(text->backgroundColor.g),
            static_cast<Uint8>(text->backgroundColor.b),
            static_cast<Uint8>(text->backgroundColor.a) };

        TTF_Font *font = loadFont(text->fontPath);
        if (font == nullptr) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            return;
        }

        SDL_Surface *textSurface
            = TTF_RenderText_Shaded(font, text->text.c_str(), textColor, backgroundColor);
        if (textSurface == nullptr) {
            std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
            return;
        }

        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (textTexture == nullptr) {
            std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
            return;
        }
        SDL_Rect textRect;
        textRect.x = static_cast<int>((text->pos.x / 100) * SCREEN_WIDTH);
        textRect.y = static_cast<int>((text->pos.y / 100) * SCREEN_HEIGHT);
        textRect.w = textSurface->w;
        textRect.h = textSurface->h;
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
} // namespace Arcade::Graph
