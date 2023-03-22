//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_TEXT_HPP
#define ARCADE_TEXT_HPP

#include "IText.hpp"

namespace Arcade::Graph
{
    class Text : public IText
    {
        public:
        Text(const std::string &id, const std::string &fontPath, const std::string &text,
            Arcade::Graph::Color &backgroundColor, Arcade::Graph::Color &foregroundColor,
            float policeSize, Arcade::Vector2f &pos);
        Text(const std::string &id, const std::string &fontPath, const std::string &text);
        ~Text() override = default;

        [[nodiscard]] const std::string &getId() const override;
        [[nodiscard]] const std::string &getFontPath() const override;
        void setFontPath(const std::string &fontPath) override;
        [[nodiscard]] const std::string &getText() const override;
        void setText(const std::string &text) override;
        [[nodiscard]] const Arcade::Graph::Color &getBackgroundColor() const override;
        void setBackgroundColor(Arcade::Graph::Color &backgroundColor) override;
        [[nodiscard]] const Arcade::Graph::Color &getForegroundColor() const override;
        void setForegroundColor(Arcade::Graph::Color &foregroundColor) override;
        [[nodiscard]] float getPoliceSize() const override;
        void setPoliceSize(float policeSize) override;
        [[nodiscard]] const Arcade::Vector2f &getPos() const override;
        void setPos(Arcade::Vector2f &pos) override;

        protected:
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
