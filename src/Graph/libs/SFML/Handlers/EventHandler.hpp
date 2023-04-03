//
// Created by valegox on 30/03/23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Events.hpp"
#include "IEventManager.hpp"

namespace Arcade::Graph
{
    class EventHandler
    {
        public:
        EventHandler() = default;
        ~EventHandler() = default;

        void run(Arcade::ECS::IEventManager &eventManager, sf::RenderWindow *window);

        private:
        static const inline std::unordered_map<sf::Keyboard::Key, const std::string> keyMap = {
            { sf::Keyboard::Escape, KEY_ESC_PRESSED },
            { sf::Keyboard::Up, KEY_UP_PRESSED },
            { sf::Keyboard::Down, KEY_DOWN_PRESSED },
            { sf::Keyboard::Left, KEY_LEFT_PRESSED },
            { sf::Keyboard::Right, KEY_RIGHT_PRESSED },
            { sf::Keyboard::Return, KEY_ENTER_PRESSED },
            { sf::Keyboard::Space, KEY_SPACE_PRESSED },
            { sf::Keyboard::BackSpace, KEY_BACKSPACE_PRESSED },
            { sf::Keyboard::Tab, KEY_TAB_PRESSED },
            { sf::Keyboard::Num1, KEY_1_PRESSED },
            { sf::Keyboard::Num2, KEY_2_PRESSED },
            { sf::Keyboard::Num3, KEY_3_PRESSED },
            { sf::Keyboard::Num4, KEY_4_PRESSED },
            { sf::Keyboard::Num5, KEY_5_PRESSED },
            { sf::Keyboard::Num6, KEY_6_PRESSED },
            { sf::Keyboard::Num7, KEY_7_PRESSED },
            { sf::Keyboard::Num8, KEY_8_PRESSED },
            { sf::Keyboard::Num9, KEY_9_PRESSED },
            { sf::Keyboard::Num0, KEY_0_PRESSED },
            { sf::Keyboard::A, KEY_A_PRESSED },
            { sf::Keyboard::B, KEY_B_PRESSED },
            { sf::Keyboard::C, KEY_C_PRESSED },
            { sf::Keyboard::D, KEY_D_PRESSED },
            { sf::Keyboard::E, KEY_E_PRESSED },
            { sf::Keyboard::F, KEY_F_PRESSED },
            { sf::Keyboard::G, KEY_G_PRESSED },
            { sf::Keyboard::H, KEY_H_PRESSED },
            { sf::Keyboard::I, KEY_I_PRESSED },
            { sf::Keyboard::J, KEY_J_PRESSED },
            { sf::Keyboard::K, KEY_K_PRESSED },
            { sf::Keyboard::L, KEY_L_PRESSED },
            { sf::Keyboard::M, KEY_M_PRESSED },
            { sf::Keyboard::N, KEY_N_PRESSED },
            { sf::Keyboard::O, KEY_O_PRESSED },
            { sf::Keyboard::P, KEY_P_PRESSED },
            { sf::Keyboard::Q, KEY_Q_PRESSED },
            { sf::Keyboard::R, KEY_R_PRESSED },
            { sf::Keyboard::S, KEY_S_PRESSED },
            { sf::Keyboard::T, KEY_T_PRESSED },
            { sf::Keyboard::U, KEY_U_PRESSED },
            { sf::Keyboard::V, KEY_V_PRESSED },
            { sf::Keyboard::W, KEY_W_PRESSED },
            { sf::Keyboard::X, KEY_X_PRESSED },
            { sf::Keyboard::Y, KEY_Y_PRESSED },
            { sf::Keyboard::Z, KEY_Z_PRESSED },
            { sf::Keyboard::Delete, KEY_DELETE_PRESSED },
            { sf::Keyboard::LAlt, KEY_ALT_PRESSED },
            { sf::Keyboard::RAlt, KEY_ALT_PRESSED },
            { sf::Keyboard::LControl, KEY_CTRL_PRESSED },
            { sf::Keyboard::RControl, KEY_CTRL_PRESSED },
            { sf::Keyboard::LShift, KEY_SHIFT_PRESSED },
            { sf::Keyboard::RShift, KEY_SHIFT_PRESSED },
            { sf::Keyboard::F1, KEY_F1_PRESSED },
            { sf::Keyboard::F2, KEY_F2_PRESSED },
            { sf::Keyboard::F3, KEY_F3_PRESSED },
            { sf::Keyboard::F4, KEY_F4_PRESSED },
            { sf::Keyboard::F5, KEY_F5_PRESSED },
            { sf::Keyboard::F6, KEY_F6_PRESSED },
            { sf::Keyboard::F7, KEY_F7_PRESSED },
            { sf::Keyboard::F8, KEY_F8_PRESSED },
            { sf::Keyboard::F9, KEY_F9_PRESSED },
            { sf::Keyboard::F10, KEY_F10_PRESSED },
            { sf::Keyboard::F11, KEY_F11_PRESSED },
            { sf::Keyboard::F12, KEY_F12_PRESSED },
        };
    };
} // namespace Arcade::Graph
