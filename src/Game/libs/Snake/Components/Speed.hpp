/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Speed
*/

#ifndef SPEED_HPP_
    #define SPEED_HPP_
    #include "Component.hpp"
    #include "ArcadeStruct.hpp"

namespace Snake {
    struct Speed final : public Arcade::ECS::Component {
        public:
            Speed(const std::string &id, float speed);
            ~Speed() final = default;

            void setSpeed(float speed);
            [[nodiscard]] float getSpeed() const;
            void setNextPoint(const Arcade::Vector3f &nextPoint);
            [[nodiscard]] const Arcade::Vector3f &getNextPoint() const;
        private:
            float _speed;
            Arcade::Vector3f _nextPoint = {-1, -1, -1};

    };
}

#endif /* !SPEED_HPP_ */
