//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITYMANAGER_HPP
#define ARCADE_ENTITYMANAGER_HPP

#include "IEntityManager.hpp"

namespace Arcade::ECS
{
    /**
     * @brief Base class for all entity managers
     */
    class EntityManager : public IEntityManager
    {
        public:
        /**
         * @brief Construct a new Entity Manager object
         */
        EntityManager();
        /**
         * @brief Destroy the Entity Manager object
         */
        ~EntityManager() override = default;

        /**
         * @brief Create an entity
         *
         * @param id The id of the entity
         * @return IEntity& The entity
         */
        IEntity &createEntity(const std::string &id) override;
        /**
         * @brief Get the Entities of the entity manager
         *
         * @return const std::vector<std::shared_ptr<IEntity>>& The entities of the entity manager
         */
        [[nodiscard]] const std::vector<std::shared_ptr<IEntity>> &getEntities() const override;
        /**
         * @brief Get the Entities of the entity manager by their component type
         *
         * @param comp The type of the component
         * @return std::unique_ptr<std::vector<std::shared_ptr<IEntity>>> The entities that have the
         * component
         */
        [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<IEntity>>>
        getEntitiesByComponentType(CompType comp) const override;
        /**
         * @brief Get the Components of the entity manager by their component type
         *
         * @param comp The type of the component
         * @return std::unique_ptr<std::vector<std::shared_ptr<IComponent>>> The components of the
         * entity manager
         */
        [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<IComponent>>>
        getComponentsByComponentType(CompType comp) const override;
        /**
         * @brief Remove an entity from the entity manager
         *
         * @param id The id of the entity
         */
        void removeEntity(const std::string &id) override;
        /**
         * @brief Remove all entities from the entity manager
         */
        void removeAllEntities() override;
        /**
         * @brief Get an entity of the entity manager by its id
         *
         * @param id The id of the entity
         * @return std::shared_ptr<IEntity> The entity
         */
        [[nodiscard]] std::shared_ptr<IEntity> getEntitiesById(
            const std::string &id) const override;

        protected:
        std::vector<std::shared_ptr<IEntity>> _entities;
    };
} // namespace Arcade::ECS

#endif // ARCADE_ENTITYMANAGER_HPP
