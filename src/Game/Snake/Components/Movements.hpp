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
            Movements();
            ~Movements();

            void setDirection(Direction direction);
            enum Direction Movements::getDirection() const;
        protected:
        private:
            Direction _direction = UP;
    };
} // namespace Snake

#endif /* !Movements_HPP_ */
