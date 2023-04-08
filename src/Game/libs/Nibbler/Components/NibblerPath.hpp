/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerPath
*/

#ifndef PATH_HPP_
    #define PATH_HPP_
    #include "Component.hpp"
    #include "Direction.hpp"
    #include "ArcadeStruct.hpp"
    #include <queue>

namespace Nibbler {
    class NibblerPath final : public Arcade::ECS::Component
    {
        public:
            NibblerPath(const std::string &id);
            ~NibblerPath() override = default;

            void addPoint(enum Direction::dir direction, Arcade::Vector3f position);
            void popPoint();
            std::pair<enum Direction::dir, Arcade::Vector3f> getPoint() const;
        private:
            std::queue<std::pair<enum Direction::dir, Arcade::Vector3f>> _path;
    };
}

#endif /* !PATH_HPP_ */
