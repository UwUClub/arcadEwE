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
        Sprite(const std::string &path, const std::string &id);
        ~Sprite() override = default;

        [[nodiscard]] const std::string &getId() const override;
        [[nodiscard]] const std::string &getPath() const override;

        void setPath(const std::string &path) override;

        [[nodiscard]] const TTYData &getTTYData() const override;
        void setTTYData(const TTYData &data) override;

        [[nodiscard]] const Arcade::Vector3f &getPos() const override;
        void setPos(Arcade::Vector3f pos) override;

        [[nodiscard]] const Arcade::Vector3f &getSize() const override;
        void setSize(Arcade::Vector3f size) override;

        [[nodiscard]] const Color &getColor() const override;
        void setColor(const Color &color) override;

        [[nodiscard]] const Rect &getRect() const override;
        void setRect(const Rect &rect) override;

        [[nodiscard]] float getScale() const override;
        void setScale(float scale) override;

        protected:
        std::string _path;
        const std::string _id;
        TTYData _cliData;
        Arcade::Vector3f _pos;
        Arcade::Vector3f _size;
        Color _color;
        Rect _rect;
        float _scale;
    };
} // namespace Arcade::Graph

#endif // ARCADE_SPRITE_HPP
