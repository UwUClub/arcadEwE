/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

int main(int ac, const char **av)
{
    if (ac > 2) {
        std::cerr << "Usage: ./arcade [lib.so]" << std::endl;
        return 84;
    }
    if (ac == 2) {
        Arcade::Core::Core core(av[1]);
        core.update();
    } else {
        Arcade::Core::Core core("");
        core.update();
    }
    return 0;
}
