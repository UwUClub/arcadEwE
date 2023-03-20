//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include "ICore.hpp"
#include "IEventManager.hpp"
#include "ISystemManager.hpp"
#include "IEntityManager.hpp"

namespace Arcade::Core {
    class Core : public ICore {
        public:
            Core();
            ~Core() override = default;

            void update() override;

            private:
                std::unique_ptr<ECS::IEventManager> _eventManager;
                std::unique_ptr<ECS::ISystemManager> _systemManager;
                std::unique_ptr<ECS::IEntityManager> _entityManager;
    };
}

#endif // ARCADE_CORE_HPP
