/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Speed
*/

#ifndef SPEED_HPP_
    #define SPEED_HPP_
    #include "Component.hpp"

namespace Snake {
    struct Speed final : public Arcade::ECS::Component {
        public:
            Speed(const std::string &id, float speed);
            ~Speed() final = default;

            void setSpeed(float speed);
            [[nodiscard]] float getSpeed() const;
        private:
            float _speed;
    };
}

#endif /* !SPEED_HPP_ */
