/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Movements
*/

#ifndef Movements_HPP_
    #define Movements_HPP_
    #include "Component.hpp"

namespace Snake {
    class Movements : public Arcade::ECS::Component
    {
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        public:
            Movements(const std::string &id, const enum Direction direction);
            ~Movements() override = default;

            void setDirection(const enum Direction direction);
            [[nodiscard]] const enum Direction getDirection() const;

        private:
            Direction _direction;
    };
} // namespace Snake

#endif /* !Movements_HPP_ */
