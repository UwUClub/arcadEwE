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

            IEntity &createEntity() override;
            const std::vector<std::unique_ptr<IEntity>> &getEntities() const override;
            const std::vector<std::unique_ptr<IEntity>> &getEntitiesByComponentType(CompType type) const override;

        protected:
        std::vector<std::unique_ptr<IEntity>> _entities;
    };
}

#endif // ARCADE_ENTITYMANAGER_HPP
