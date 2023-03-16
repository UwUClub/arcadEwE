//
// Created by patatofour on 16/03/23.
//

#ifndef ARCADE_CORE_HPP
#define ARCADE_CORE_HPP

#include <memory>
#include "ICore.hpp"

namespace Arcade::Core
{
    class Core : public Arcade::Core::ICore
    {
        public:
            Core();
            ~Core() override;

            int run(int ac, const char **av);
        private:

    };
}

#endif // ARCADE_CORE_HPP
