//
// Created by valegox on 27/03/23.
//

#include <ncurses.h>
#include <iostream>
#include "ArcadeStruct.hpp"
#include "EventHandler.hpp"

namespace Arcade::Graph
{

    static const std::map<const char, const std::string> keys = {
        { KEY_MOUSE, "MOUSE_KEY1_PRESSED" }, { KEY_MOUSE, "MOUSE_KEY2_PRESSED" },
        { KEY_MOUSE, "MOUSE_KEY3_PRESSED" }, { KEY_MOUSE, "MOUSE_KEY4_PRESSED" },
        { KEY_MOUSE, "MOUSE_KEY5_PRESSED" }, { 'a', "KEY_A_PRESSED" }, { 'A', "KEY_A_PRESSED" },
        { 'b', "KEY_B_PRESSED" }, { 'B', "KEY_B_PRESSED" }, { 'c', "KEY_C_PRESSED" },
        { 'C', "KEY_C_PRESSED" }, { 'd', "KEY_D_PRESSED" }, { 'D', "KEY_D_PRESSED" },
        { 'e', "KEY_E_PRESSED" }, { 'E', "KEY_E_PRESSED" }, { 'f', "KEY_F_PRESSED" },
        { 'F', "KEY_F_PRESSED" }, { 'g', "KEY_G_PRESSED" }, { 'G', "KEY_G_PRESSED" },
        { 'h', "KEY_H_PRESSED" }, { 'H', "KEY_H_PRESSED" }, { 'i', "KEY_I_PRESSED" },
        { 'I', "KEY_I_PRESSED" }, { 'j', "KEY_J_PRESSED" }, { 'J', "KEY_J_PRESSED" },
        { 'k', "KEY_K_PRESSED" }, { 'K', "KEY_K_PRESSED" }, { 'l', "KEY_L_PRESSED" },
        { 'L', "KEY_L_PRESSED" }, { 'm', "KEY_M_PRESSED" }, { 'M', "KEY_M_PRESSED" },
        { 'n', "KEY_N_PRESSED" }, { 'N', "KEY_N_PRESSED" }, { 'o', "KEY_O_PRESSED" },
        { 'O', "KEY_O_PRESSED" }, { 'p', "KEY_P_PRESSED" }, { 'P', "KEY_P_PRESSED" },
        { 'q', "KEY_Q_PRESSED" }, { 'Q', "KEY_Q_PRESSED" }, { 'r', "KEY_R_PRESSED" },
        { 'R', "KEY_R_PRESSED" }, { 's', "KEY_S_PRESSED" }, { 'S', "KEY_S_PRESSED" },
        { 't', "KEY_T_PRESSED" }, { 'T', "KEY_T_PRESSED" }, { 'u', "KEY_U_PRESSED" },
        { 'U', "KEY_U_PRESSED" }, { 'v', "KEY_V_PRESSED" }, { 'V', "KEY_V_PRESSED" },
        { 'w', "KEY_W_PRESSED" }, { 'W', "KEY_W_PRESSED" }, { 'x', "KEY_X_PRESSED" },
        { 'X', "KEY_X_PRESSED" }, { 'y', "KEY_Y_PRESSED" }, { 'Y', "KEY_Y_PRESSED" },
        { 'z', "KEY_Z_PRESSED" }, { 'Z', "KEY_Z_PRESSED" }, { '0', "KEY_0_PRESSED" },
        { '1', "KEY_1_PRESSED" }, { '2', "KEY_2_PRESSED" }, { '3', "KEY_3_PRESSED" },
        { '4', "KEY_4_PRESSED" }, { '5', "KEY_5_PRESSED" }, { '6', "KEY_6_PRESSED" },
        { '7', "KEY_7_PRESSED" }, { '8', "KEY_8_PRESSED" }, { '9', "KEY_9_PRESSED" },
        { ' ', "KEY_SPACE_PRESSED" }, { KEY_ENTER, "KEY_ENTER_PRESSED" }, { 27, "KEY_ESC_PRESSED" },
        { KEY_UP, "KEY_UP_PRESSED" }, { KEY_DOWN, "KEY_DOWN_PRESSED" },
        { KEY_LEFT, "KEY_LEFT_PRESSED" }, { KEY_RIGHT, "KEY_RIGHT_PRESSED" },
        { 9, "KEY_TAB_PRESSED" }, { KEY_BACKSPACE, "KEY_BACKSPACE_PRESSED" },
        { KEY_DC, "KEY_DELETE_PRESSED" }, { KEY_SLEFT, "KEY_SHIFT_PRESSED" },
        { KEY_SRIGHT, "KEY_SHIFT_PRESSED" }, { 17, "KEY_CTRL_PRESSED" }, { 18, "KEY_ALT_PRESSED" },
        { KEY_F(1), "KEY_F1_PRESSED" }, { KEY_F(2), "KEY_F2_PRESSED" },
        { KEY_F(3), "KEY_F3_PRESSED" }, { KEY_F(4), "KEY_F4_PRESSED" },
        { KEY_F(5), "KEY_F5_PRESSED" }, { KEY_F(6), "KEY_F6_PRESSED" },
        { KEY_F(7), "KEY_F7_PRESSED" }, { KEY_F(8), "KEY_F8_PRESSED" },
        { KEY_F(9), "KEY_F9_PRESSED" }, { KEY_F(10), "KEY_F10_PRESSED" },
        { KEY_F(11), "KEY_F11_PRESSED" }, { KEY_F(12), "KEY_F12_PRESSED" },
        { KEY_RESIZE, "WINDOW_RESIZE" }, { KEY_MIN, "WINDOW_MINIMIZE" }
    };

    EventHandler::EventHandler()
    {
    }

    void EventHandler::run([[maybe_unused]] float delta, Arcade::ECS::IEventManager &eventManager,
        [[maybe_unused]] Arcade::ECS::IEntityManager &entityManager)
    {
        const char key = getch();

        eventManager.clearEvents();

        if (key == ERR) {
            return;
        }
        if (keys.find(key) != keys.end()) {
            std::string eventName = keys.find(key)->second;
            std::cout << eventName << std::endl;
            eventManager.addEvent(eventName, nullptr);
        }
    }
} // namespace Arcade::Graph
