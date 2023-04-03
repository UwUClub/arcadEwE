/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** BoxCollider
*/

#ifndef BOXCOLLIDER_HPP_
    #define BOXCOLLIDER_HPP_
    #include "Component.hpp"
    #include "ArcadeStruct.hpp"
    #include "Transform.hpp"
    #include "IEntity.hpp"
    #include <vector>

namespace Snake {
    struct BoxCollider final : public Arcade::ECS::Component {
        public:
            BoxCollider(const std::string &id, Arcade::Vector3f box, Transform &transform);
            ~BoxCollider() final = default;

            void setBox(Arcade::Vector3f box);
            Arcade::Vector3f getBox() const;
            virtual void OnCollisionEnter(const Arcade::ECS::IEntity &entity);
            virtual void OnCollisionStay(const Arcade::ECS::IEntity &entity);
            virtual void OnCollisionExit(const Arcade::ECS::IEntity &entity);
            bool IsColliding(const BoxCollider &other) const;

        public:
            Arcade::Vector3f box;
            Transform &transform;
            bool isEnabled = true;
            std::vector<Arcade::ECS::IEntity *> _collidingEntities;
    };
}

#endif /* !BOXCOLLIDER_HPP_ */
