//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_ENTITYMANAGER_HPP
#define ARCADE_ENTITYMANAGER_HPP

#include "IEntityManager.hpp"

namespace Arcade::ECS {
    class EntityManager : public IEntityManager {
        public:
            EntityManager();
            ~EntityManager() override = default;

            IEntity &createEntity(const std::string &id) override;
            [[nodiscard]] const std::vector<std::shared_ptr<IEntity>> &getEntities() const override;
            [[nodiscard]] std::unique_ptr<std::vector<std::shared_ptr<IEntity>>>
            getEntitiesByComponentType(CompType comp) const override;
            void removeEntity(std::string id) override;
            void removeAllEntities() override;

        protected:
            std::vector<std::shared_ptr<IEntity>> _entities;
    };
}

#endif // ARCADE_ENTITYMANAGER_HPP
