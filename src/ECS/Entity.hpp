//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITY_HPP
#define ARCADE_ENTITY_HPP

#include "IEntity.hpp"
#include "IComponent.hpp"

namespace Arcade::ECS
{
    class Entity : public IEntity
    {
        public:
        explicit Entity(const std::string &id);
        ~Entity() override = default;

        [[nodiscard]] std::string getId() const override;
        [[nodiscard]] const std::map<CompType, std::vector<std::shared_ptr<IComponent>>> &
        getComponents() const override;
        IComponent &getComponents(const std::string &id) override;
        [[nodiscard]] const std::vector<std::shared_ptr<IComponent>> &getComponents(
            CompType type) const override;
        void addComponent(std::shared_ptr<IComponent> component) override;
        void removeComponent(const std::string &id) override;
        void removeComponent(CompType type) override;

        protected:
        class EntityException : public std::exception
        {
            public:
            explicit EntityException(const std::string &message)
                : _message(message)
            {
            }

            [[nodiscard]] const char *what() const noexcept override { return _message.c_str(); }

            private:
            std::string _message;
        };

        const std::string _id;
        std::map<Arcade::ECS::CompType, std::vector<std::shared_ptr<Arcade::ECS::IComponent>>>
            _components;
    };
} // namespace Arcade::ECS

#endif // ARCADE_ENTITY_HPP
