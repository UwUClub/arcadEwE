//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITY_HPP
#define ARCADE_ENTITY_HPP

#include "IEntity.hpp"
#include "IComponent.hpp"

namespace Arcade::ECS {
    class Entity : public IEntity {
        public:
            explicit Entity(std::string id);
            ~Entity() override = default;

            [[nodiscard]] std::string getId() const override;
            const std::map<CompType, std::vector<std::unique_ptr<IComponent>>> &getComponents() override;
            const std::vector<std::unique_ptr<IComponent>> &getComponents(CompType type) override;
            void addComponent(std::unique_ptr<IComponent> component) override;
            void removeComponent(std::string id) override;
            void removeComponents(CompType type) override;

        protected:
            std::string _id;
            std::map<Arcade::ECS::CompType, std::vector<std::unique_ptr<Arcade::ECS::IComponent>>> _components;
    };
}

#endif // ARCADE_ENTITY_HPP
