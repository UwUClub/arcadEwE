//
// Created by patatofour on 21/03/23.
//

#ifndef ARCADE_SPRITE_HPP
#define ARCADE_SPRITE_HPP

#include "ISprite.hpp"

namespace Arcade::Graph
{
    class Sprite : public ISprite
    {
        public:
        Sprite(std::string path, std::string id);
        ~Sprite() override = default;

        [[nodiscard]] const std::string &getId() const override;
        [[nodiscard]] const std::string &getPath() const override;

        [[nodiscard]] const TTYData &getNcurseData() const override;

        [[nodiscard]] const Arcade::Vector3f &getPos() const override;
        void setPos(Arcade::Vector3f pos) override;

        [[nodiscard]] const Arcade::Vector3f &getSize() const override;
        void setSize(Arcade::Vector3f size) override;

        [[nodiscard]] const Color &getColor() const;
        void setColor(Color color) override;

        [[nodiscard]] const Rect &getRect() const override;
        void setRect(Rect rect) override;

        [[nodiscard]] const float &getScale() const override;
        void setScale(float scale) override;

        protected:
        std::string _path;
        std::string _id;
        TTYData _ncurseData;
        Arcade::Vector3f _pos;
        Arcade::Vector3f _size;
        Color _color;
        Rect _rect;
        float _scale;
    };
} // namespace Arcade::Graph

#endif // ARCADE_SPRITE_HPP
