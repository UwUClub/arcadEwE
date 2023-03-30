//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITY_HPP
#define ARCADE_ENTITY_HPP

#include "IEntity.hpp"
#include "IComponent.hpp"

namespace Arcade::ECS
{
    /**
     * @brief Base class for all entities
     */
    class Entity : public IEntity
    {
        public:
        /**
         * @brief Construct a new Entity object
         *
         * @param id The id of the entity
         */
        explicit Entity(const std::string &id);
        /**
         * @brief Destroy the Entity object
         */
        ~Entity() override = default;

        /**
         * @brief Get the Id of the entity
         *
         * @return const std::string& The id of the entity
         */
        [[nodiscard]] std::string getId() const override;
        /**
         * @brief Get the Components of the entity
         *
         * @return const std::map<CompType, std::vector<std::shared_ptr<IComponent>>>& The
         * components of the entity
         */
        [[nodiscard]] const std::map<CompType, std::vector<std::shared_ptr<IComponent>>> &
        getComponents() const override;
        /**
         * @brief Get the Components of the entity by id
         *
         * @param id The id of the component
         * @return IComponent& The component of the entity
         */
        IComponent &getComponents(const std::string &id) override;
        /**
         * @brief Get the Components of the entity by type
         *
         * @param type The type of the component
         * @return const std::vector<std::shared_ptr<IComponent>>& The components of the entity
         */
        [[nodiscard]] const std::vector<std::shared_ptr<IComponent>> &getComponents(
            CompType type) const override;
        /**
         * @brief Add a component to the entity
         * @param component The component to add
         */
        void addComponent(std::shared_ptr<IComponent> component) override;
        /**
         * @brief Remove a component from the entity
         * @param id The id of the component to remove
         */
        void removeComponent(const std::string &id) override;
        /**
         * @brief Remove a component from the entity
         * @param type The type of the component to remove
         */
        void removeComponent(CompType type) override;

        protected:
        /**
         * @brief Exception class for the Entity class
         */
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
