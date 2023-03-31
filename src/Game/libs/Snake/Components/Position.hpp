/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** Position
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_
    #include "Component.hpp"
    #include "ArcadeStruct.hpp"

namespace Snake {
    struct Position final : public Arcade::ECS::Component {
        public:
            Position(const std::string &id, Arcade::Vector3f pos);
            ~Position() final = default;

        public:
            Arcade::Vector3f pos;
    };
}

#endif /* !POSITION_HPP_ */
