//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITYMANAGER_HPP
#define ARCADE_ENTITYMANAGER_HPP

#include "IEntityManager.hpp"

namespace Arcade::ECS
{
    class EntityManager : public IEntityManager
    {
        public:
        EntityManager();
        ~EntityManager() override = default;

        IEntity &createEntity(const std::string &id) override;
        [[nodiscard]] const std::vector<std::shared_ptr<IEntity>> &getEntities() const override;
        [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<IEntity>>>
        getEntitiesByComponentType(CompType comp) const override;
        [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<IComponent>>>
        getComponentsByComponentType(CompType comp) const override;
        void removeEntity(const std::string &id) override;
        void removeAllEntities() override;
        [[nodiscard]] std::shared_ptr<IEntity> getEntitiesById(
            const std::string &id) const override;

        protected:
        std::vector<std::shared_ptr<IEntity>> _entities;
    };
} // namespace Arcade::ECS

#endif // ARCADE_ENTITYMANAGER_HPP
