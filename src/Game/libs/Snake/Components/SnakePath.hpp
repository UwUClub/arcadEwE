/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** SnakePath
*/

#ifndef PATH_HPP_
    #define PATH_HPP_
    #include "Component.hpp"
    #include "Direction.hpp"
    #include "ArcadeStruct.hpp"
    #include <queue>

namespace Snake {
    class SnakePath final : public Arcade::ECS::Component
    {
        public:
            SnakePath(const std::string &id);
            ~SnakePath() override = default;

            void addPoint(enum Direction::dir direction, Arcade::Vector3f position);
            void popPoint();
            std::pair<enum Direction::dir, Arcade::Vector3f> getPoint() const;
        private:
            std::queue<std::pair<enum Direction::dir, Arcade::Vector3f>> _path;
    };
}

#endif /* !PATH_HPP_ */
