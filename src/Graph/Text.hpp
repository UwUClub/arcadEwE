//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "IText.hpp"
#include "Component.hpp"

#define FONT_PATH         "assets/fonts/arcade.ttf"
#define FONT_SIZE         25
#define AVERAGE_CHAR_SIZE 0.6f

namespace Arcade::Graph
{
    class Text : public IText
    {
        public:
        Text(const std::string &id, const std::string &text,
            const Arcade::Graph::Color &backgroundColor,
            const Arcade::Graph::Color &foregroundColor, const Arcade::Vector2f &pos,
            const std::string &fontPath = FONT_PATH, float policeSize = FONT_SIZE);
        ~Text() override = default;

        [[nodiscard]] const std::string &getId() const override;
        [[nodiscard]] ECS::CompType getType() const override;
        [[nodiscard]] const std::string &getFontPath() const override;
        void setFontPath(const std::string &fontPath) override;
        [[nodiscard]] const std::string &getText() const override;
        void setText(const std::string &text) override;
        [[nodiscard]] const Arcade::Graph::Color &getBackgroundColor() const override;
        void setBackgroundColor(const Arcade::Graph::Color &backgroundColor) override;
        [[nodiscard]] const Arcade::Graph::Color &getForegroundColor() const override;
        void setForegroundColor(const Arcade::Graph::Color &foregroundColor) override;
        [[nodiscard]] float getPoliceSize() const override;
        void setPoliceSize(float policeSize) override;
        [[nodiscard]] const Arcade::Vector2f &getPos() const override;
        void setPos(const Arcade::Vector2f &pos) override;

        protected:
        const ECS::CompType _type { ECS::CompType::TEXT };
        const std::string _id;
        std::string _fontPath;
        std::string _text;
        Arcade::Graph::Color _backgroundColor;
        Arcade::Graph::Color _foregroundColor;
        float _fontSize;
        Arcade::Vector2f _pos;
    };
} // namespace Arcade::Graph
#endif // ARCADE_TEXT_HPP
