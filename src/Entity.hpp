//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITY_HPP
#define ARCADE_ENTITY_HPP

#include "IEntity.hpp"

namespace Arcade::ECS {
    class Entity : public IEntity {
        public:
            Entity(std::size_t id);
            ~Entity() override = default;

            [[nodiscard]] std::size_t getId() const override;
            const std::vector<std::unique_ptr<IComponent>> &
                getComponents() override;
            const std::vector<std::unique_ptr<IComponent>> &
                getComponents(CompType type) override;
            void addComponent(std::unique_ptr<IComponent> component) override;

        protected:
            std::size_t _id;
            std::vector<std::unique_ptr<IComponent>> _components;
    };
}

#endif // ARCADE_ENTITY_HPP
