//
// Created by valegox on 27/03/23.
//

#include <ncurses.h>
#include "AHandler.hpp"

namespace Arcade::Graph
{

    AHandler::AHandler() : _nbColorPairs(0), _nbColors(0)
    {
    }

    void AHandler::printContent(std::string content, int posX, int posY, Color foregroundColor,
        Color backgroundColor)
    {
        if (has_colors()) {
            _nbColorPairs++;
            _nbColors++;
            init_color(_nbColors, foregroundColor.r, foregroundColor.g, foregroundColor.b);
            _nbColors++;
            init_color(_nbColors, backgroundColor.r, backgroundColor.g, backgroundColor.b);
            init_pair(_nbColorPairs, _nbColors - 1, _nbColors);
            attron(COLOR_PAIR(_nbColorPairs));
        }
        mvprintw(posY, posX, "%s", content.c_str());
        if (has_colors()) {
            attroff(COLOR_PAIR(_nbColorPairs));
        }
    }

    void AHandler::resetColors()
    {
        _nbColorPairs = 0;
        _nbColors = 0;
    }
} // namespace Arcade::Graph
