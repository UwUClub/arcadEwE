//
// Created by patatofour on 31/03/23.
//

#ifndef ARCADE_ONEVENT_HPP
#define ARCADE_ONEVENT_HPP

#include <SDL.h>
#include <unordered_map>
#include "IEventManager.hpp"
#include "Events.hpp"

namespace Arcade::Graph
{
    class OnEvent
    {
        public:
        OnEvent();
        ~OnEvent() = default;

        void run(Arcade::ECS::IEventManager &eventManager, SDL_Event &event);

        private:
        static const inline std::unordered_map<Uint32, const std::string> baseEventMap = {
            { SDL_QUIT, QUIT },
            { SDL_KEYDOWN, KEY_DOWN_PRESSED },
            { SDL_KEYUP, KEY_UP_PRESSED },
        };

        static const inline std::unordered_map<Uint32, const std::string> windowEventMap = {
            { SDL_WINDOWEVENT_CLOSE, WINDOW_CLOSE },
            { SDL_WINDOWEVENT_RESIZED, WINDOW_RESIZE },
            { SDL_WINDOWEVENT_SIZE_CHANGED, WINDOW_RESIZE },
            { SDL_WINDOWEVENT_MINIMIZED, WINDOW_MINIMIZE },
            { SDL_WINDOWEVENT_MAXIMIZED, WINDOW_MAXIMIZE },
        };

        static const inline std::unordered_map<SDL_Keycode, const std::string> keyMap = {
            { SDLK_ESCAPE, KEY_ESC_PRESSED },
            { SDLK_UP, KEY_UP_PRESSED },
            { SDLK_DOWN, KEY_DOWN_PRESSED },
            { SDLK_LEFT, KEY_LEFT_PRESSED },
            { SDLK_RIGHT, KEY_RIGHT_PRESSED },
            { SDLK_RETURN, KEY_ENTER_PRESSED },
            { SDLK_SPACE, KEY_SPACE_PRESSED },
            { SDLK_BACKSPACE, KEY_BACKSPACE_PRESSED },
            { SDLK_TAB, KEY_TAB_PRESSED },
            { SDLK_1, KEY_1_PRESSED },
            { SDLK_2, KEY_2_PRESSED },
            { SDLK_3, KEY_3_PRESSED },
            { SDLK_4, KEY_4_PRESSED },
            { SDLK_5, KEY_5_PRESSED },
            { SDLK_6, KEY_6_PRESSED },
            { SDLK_7, KEY_7_PRESSED },
            { SDLK_8, KEY_8_PRESSED },
            { SDLK_9, KEY_9_PRESSED },
            { SDLK_0, KEY_0_PRESSED },
            { SDLK_a, KEY_A_PRESSED },
            { SDLK_b, KEY_B_PRESSED },
            { SDLK_c, KEY_C_PRESSED },
            { SDLK_d, KEY_D_PRESSED },
            { SDLK_e, KEY_E_PRESSED },
            { SDLK_f, KEY_F_PRESSED },
            { SDLK_g, KEY_G_PRESSED },
            { SDLK_h, KEY_H_PRESSED },
            { SDLK_i, KEY_I_PRESSED },
            { SDLK_j, KEY_J_PRESSED },
            { SDLK_k, KEY_K_PRESSED },
            { SDLK_l, KEY_L_PRESSED },
            { SDLK_m, KEY_M_PRESSED },
            { SDLK_n, KEY_N_PRESSED },
            { SDLK_o, KEY_O_PRESSED },
            { SDLK_p, KEY_P_PRESSED },
            { SDLK_q, KEY_Q_PRESSED },
            { SDLK_r, KEY_R_PRESSED },
            { SDLK_s, KEY_S_PRESSED },
            { SDLK_t, KEY_T_PRESSED },
            { SDLK_u, KEY_U_PRESSED },
            { SDLK_v, KEY_V_PRESSED },
            { SDLK_w, KEY_W_PRESSED },
            { SDLK_x, KEY_X_PRESSED },
            { SDLK_y, KEY_Y_PRESSED },
            { SDLK_z, KEY_Z_PRESSED },
            { SDLK_F1, KEY_F1_PRESSED },
            { SDLK_F2, KEY_F2_PRESSED },
            { SDLK_F3, KEY_F3_PRESSED },
            { SDLK_F4, KEY_F4_PRESSED },
            { SDLK_F5, KEY_F5_PRESSED },
            { SDLK_F6, KEY_F6_PRESSED },
            { SDLK_F7, KEY_F7_PRESSED },
            { SDLK_F8, KEY_F8_PRESSED },
            { SDLK_F9, KEY_F9_PRESSED },
            { SDLK_F10, KEY_F10_PRESSED },
            { SDLK_F11, KEY_F11_PRESSED },
            { SDLK_F12, KEY_F12_PRESSED },
            { SDLK_DELETE, KEY_DELETE_PRESSED },
            { SDLK_LSHIFT, KEY_SHIFT_PRESSED },
            { SDLK_RSHIFT, KEY_SHIFT_PRESSED },
            { SDLK_RCTRL, KEY_CTRL_PRESSED },
            { SDLK_LCTRL, KEY_CTRL_PRESSED },
            { SDLK_RALT, KEY_ALT_PRESSED },
            { SDLK_LALT, KEY_ALT_PRESSED },
        };

        static const inline std::unordered_map<Uint8, const std::string> mouseButtonMap = {
            { SDL_BUTTON_LEFT, MOUSE_CLICK_1 },
            { SDL_BUTTON_RIGHT, MOUSE_CLICK_2 },
            { SDL_BUTTON_MIDDLE, MOUSE_CLICK_1 },
        };
    };
} // namespace Arcade::Graph

#endif // ARCADE_ONEVENT_HPP
