//
// Created by valegox on 02/04/23.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Events.hpp"
#include "EventHandler.hpp"
#include "ArcadeStruct.hpp"

namespace Arcade::Graph {

    static const std::map<int, std::string> keys = {
        { 42, KEY_A_PRESSED }, //{ sf::Keyboard::B, KEY_B_PRESSED },
        // { sf::Keyboard::C, KEY_C_PRESSED }, { sf::Keyboard::D, KEY_D_PRESSED },
        // { sf::Keyboard::E, KEY_E_PRESSED }, { sf::Keyboard::F, KEY_F_PRESSED },
        // { sf::Keyboard::G, KEY_G_PRESSED }, { sf::Keyboard::H, KEY_H_PRESSED },
        // { sf::Keyboard::I, KEY_I_PRESSED }, { sf::Keyboard::J, KEY_J_PRESSED },
        // { sf::Keyboard::K, KEY_K_PRESSED }, { sf::Keyboard::L, KEY_L_PRESSED },
        // { sf::Keyboard::M, KEY_M_PRESSED }, { sf::Keyboard::N, KEY_N_PRESSED },
        // { sf::Keyboard::O, KEY_O_PRESSED }, { sf::Keyboard::P, KEY_P_PRESSED },
        // { sf::Keyboard::Q, KEY_Q_PRESSED }, { sf::Keyboard::R, KEY_R_PRESSED },
        // { sf::Keyboard::S, KEY_S_PRESSED }, { sf::Keyboard::T, KEY_T_PRESSED },
        // { sf::Keyboard::U, KEY_U_PRESSED }, { sf::Keyboard::V, KEY_V_PRESSED },
        // { sf::Keyboard::W, KEY_W_PRESSED }, { sf::Keyboard::X, KEY_X_PRESSED },
        // { sf::Keyboard::Y, KEY_Y_PRESSED }, { sf::Keyboard::Z, KEY_Z_PRESSED },
        // { sf::Keyboard::Num0, KEY_0_PRESSED }, { sf::Keyboard::Num1, KEY_1_PRESSED },
        // { sf::Keyboard::Num2, KEY_2_PRESSED }, { sf::Keyboard::Num3, KEY_3_PRESSED },
        // { sf::Keyboard::Num4, KEY_4_PRESSED }, { sf::Keyboard::Num5, KEY_5_PRESSED },
        // { sf::Keyboard::Num6, KEY_6_PRESSED }, { sf::Keyboard::Num7, KEY_7_PRESSED },
        // { sf::Keyboard::Num8, KEY_8_PRESSED }, { sf::Keyboard::Num9, KEY_9_PRESSED },
        // { sf::Keyboard::Space, KEY_SPACE_PRESSED }, { sf::Keyboard::Enter, KEY_ENTER_PRESSED },
        // { sf::Keyboard::Escape, QUIT }, { sf::Keyboard::Up, KEY_UP_PRESSED },
        // { sf::Keyboard::Down, KEY_DOWN_PRESSED }
    };

    void EventHandler::run(Arcade::ECS::IEventManager &eventManager, sf::RenderWindow *window)
    {
        sf::Event _event;
        window->pollEvent(_event);
        if (_event.type == sf::Event::Closed) {
            eventManager.addEvent(QUIT, nullptr);
            return;
        }
        if (_event.type == sf::Event::KeyPressed) {
            std::cout << "detected key press " << _event.key.code << std::endl;
            std::cout << keys.at(42) << std::endl;
            //std::find(keys.begin(), keys.end(), 42);
            // if (keys.find(key) != keys.end()) {
            //     std::cout << "test" << std::endl;
            // //     //std::cout << "detected\n";
            // //     // std::string eventName = keys.find(_event.key)->second;
            // //     // eventManager.addEvent(eventName, nullptr);
            // }
            // std::string eventName = keys.find(_event.key)->second;
            // eventManager.addEvent(eventName, nullptr);
        }
    }
}
