//
// Created by patatofour on 07/04/23.
//

#ifndef ARCADE_BUFFERWRITERMANAGER_HPP
#define ARCADE_BUFFERWRITERMANAGER_HPP

#include <unordered_map>
#include <string>
#include "ISystem.hpp"
#include "Component.hpp"
#include "Events.hpp"

namespace Nibbler
{
    class BufferWriterManager : public Arcade::ECS::ISystem
    {
        public:
        BufferWriterManager(size_t score);
        ~BufferWriterManager() override = default;

        void run(double deltaTime, Arcade::ECS::IEventManager &eventManager,
            Arcade::ECS::IEntityManager &entityManager) override;

        private:
        size_t _score;
        static const inline std::unordered_map<std::string, std::string> _keyMap = {
            { KEY_0_PRESSED, "0" },
            { KEY_1_PRESSED, "1" },
            { KEY_2_PRESSED, "2" },
            { KEY_3_PRESSED, "3" },
            { KEY_4_PRESSED, "4" },
            { KEY_5_PRESSED, "5" },
            { KEY_6_PRESSED, "6" },
            { KEY_7_PRESSED, "7" },
            { KEY_8_PRESSED, "8" },
            { KEY_9_PRESSED, "9" },
            { KEY_A_PRESSED, "A" },
            { KEY_B_PRESSED, "B" },
            { KEY_C_PRESSED, "C" },
            { KEY_D_PRESSED, "D" },
            { KEY_E_PRESSED, "E" },
            { KEY_F_PRESSED, "F" },
            { KEY_G_PRESSED, "G" },
            { KEY_H_PRESSED, "H" },
            { KEY_I_PRESSED, "I" },
            { KEY_J_PRESSED, "J" },
            { KEY_K_PRESSED, "K" },
            { KEY_L_PRESSED, "L" },
            { KEY_M_PRESSED, "M" },
            { KEY_N_PRESSED, "N" },
            { KEY_O_PRESSED, "O" },
            { KEY_P_PRESSED, "P" },
            { KEY_Q_PRESSED, "Q" },
            { KEY_R_PRESSED, "R" },
            { KEY_S_PRESSED, "S" },
            { KEY_T_PRESSED, "T" },
            { KEY_U_PRESSED, "U" },
            { KEY_V_PRESSED, "V" },
            { KEY_W_PRESSED, "W" },
            { KEY_X_PRESSED, "X" },
            { KEY_Y_PRESSED, "Y" },
            { KEY_Z_PRESSED, "Z" },
            { KEY_SPACE_PRESSED, " " },
            { KEY_DELETE_PRESSED, "-1" },
            { KEY_ENTER_PRESSED, "ENTER" },
        };
        std::vector<std::string> getEventsTriggered(Arcade::ECS::IEventManager &eventManager);
        void saveBuffer(const std::string &buffer);
    };
} // namespace Nibbler
#endif // ARCADE_BUFFERWRITERMANAGER_HPP
