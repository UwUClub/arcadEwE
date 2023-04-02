//
// Created by valegox on 27/03/23.
//

#include <ncurses.h>
#include "AHandler.hpp"

namespace Arcade::Graph
{

    AHandler::AHandler()
    {
    }

    void AHandler::printContent(std::string content, int posX, int posY, Color foregroundColor,
        Color backgroundColor)
    {
        if (has_colors()) {
            init_color(0, foregroundColor.r, foregroundColor.g, foregroundColor.b);
            init_color(1, backgroundColor.r, backgroundColor.g, backgroundColor.b);
            init_pair(2, 0, 1);
            attron(COLOR_PAIR(2));
        }
        mvprintw(posY, posX, "%s", content.c_str());
        if (has_colors()) {
            attroff(COLOR_PAIR(2));
        }
    }
} // namespace Arcade::Graph
