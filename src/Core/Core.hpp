//
// Created by patatofour on 20/03/23.
//

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include "ICore.hpp"
#include "IGameModule.hpp"
#include "DisplayModule.hpp"
#include "Api.hpp"

namespace Arcade::Core {
    class Core : public ICore {
        public:
            Core();
            ~Core() override = default;

            void run();

            private:
                std::unique_ptr<IGameModule> _gameModule;
                std::unique_ptr<DisplayModule> _displayModule;
    };
}

#endif // ARCADE_CORE_HPP
