/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Direction
*/

#ifndef Direction_HPP_
    #define Direction_HPP_
    #include "Component.hpp"

namespace Nibbler {
    class Direction : public Arcade::ECS::Component
    {
        public:
            enum dir {
                UP,
                DOWN,
                LEFT,
                RIGHT
            };

        public:
            Direction(const std::string &id, const enum dir direction);
            ~Direction() override = default;

            void setDirection(const enum dir direction);
            [[nodiscard]] enum dir getDirection() const;
            void setNextDirection(const enum dir direction);
            [[nodiscard]] enum dir getNextDirection() const;

        private:
            dir _direction;
            dir _nextDirection;
    };
} // namespace Nibbler

#endif /* !Direction_HPP_ */
