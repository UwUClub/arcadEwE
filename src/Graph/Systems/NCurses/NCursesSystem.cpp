//
// Created by valegox on 22/03/23.
//

#include <ncurses.h>
#include "NCursesSystem.hpp"
#include "IScene.hpp"
#include "IGameModule.hpp"
#include "IScene.hpp"
#include "ArcadeStruct.hpp"
#include "Component.hpp"
#include "ISprite.hpp"
#include "IText.hpp"

Arcade::Graph::NCursesSystem::NCursesSystem()
{
    initscr();
    printw("Hello World");
}

Arcade::Graph::NCursesSystem::~NCursesSystem()
{
    endwin();
}

static void printContent(std::string content, int posX, int posY, Arcade::Graph::Color foregroundColor, Arcade::Graph::Color backgroundColor)
{
    if (has_colors()) {
        init_color(0, foregroundColor.r, foregroundColor.g, foregroundColor.b);
        init_color(1, backgroundColor.r, backgroundColor.g, backgroundColor.b);
        init_pair(2, 0, 1);
        attron(COLOR_PAIR(2));
    }
    mvprintw(posY, posX, content.c_str());
    if (has_colors()) {
        attroff(COLOR_PAIR(2));
    }
}

static void displaySprites(std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (auto &entity : entities) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents = entity->getComponents(Arcade::ECS::CompType::SPRITE);

        for (auto spriteComponent : spriteComponents) {
            auto sprite = std::static_pointer_cast<Arcade::Graph::ISprite>(spriteComponent);
            Arcade::Vector3f pos = (*sprite).getPos();
            Arcade::Graph::TTYData data = (*sprite).getTTYData();

            printContent(data.defaultChar, pos.x, pos.y, data.foreground, data.background);
        }
    }
}

static void displayTexts(std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (auto &entity : entities) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

        for (auto textComponent : textComponents) {
            auto text = std::static_pointer_cast<Arcade::Graph::IText>(textComponent);
            Arcade::Vector2f pos = (*text).getPos();
            Arcade::Graph::Color foregroundColor = (*text).getForegroundColor();
            Arcade::Graph::Color backgroundColor = (*text).getBackgroundColor();

            printContent((*text).getText(), pos.x, pos.y, foregroundColor, backgroundColor);
        }
    }
}

static void captureKeyboardEvents(Arcade::ECS::IEventManager &eventManager)
{
    const char key = getch();

    if (key == ERR) {
        return;
    }

    std::map<const char, const std::string> keys = {
        {KEY_MOUSE, "MOUSE_KEY1_PRESSED"},
        {KEY_MOUSE, "MOUSE_KEY2_PRESSED"},
        {KEY_MOUSE, "MOUSE_KEY3_PRESSED"},
        {KEY_MOUSE, "MOUSE_KEY4_PRESSED"},
        {KEY_MOUSE, "MOUSE_KEY5_PRESSED"},
        {'a', "KEY_A_PRESSED"},
        {'A', "KEY_A_PRESSED"},
        {'b', "KEY_B_PRESSED"},
        {'B', "KEY_B_PRESSED"},
        {'c', "KEY_C_PRESSED"},
        {'C', "KEY_C_PRESSED"},
        {'d', "KEY_D_PRESSED"},
        {'D', "KEY_D_PRESSED"},
        {'e', "KEY_E_PRESSED"},
        {'E', "KEY_E_PRESSED"},
        {'f', "KEY_F_PRESSED"},
        {'F', "KEY_F_PRESSED"},
        {'g', "KEY_G_PRESSED"},
        {'G', "KEY_G_PRESSED"},
        {'h', "KEY_H_PRESSED"},
        {'H', "KEY_H_PRESSED"},
        {'i', "KEY_I_PRESSED"},
        {'I', "KEY_I_PRESSED"},
        {'j', "KEY_J_PRESSED"},
        {'J', "KEY_J_PRESSED"},
        {'k', "KEY_K_PRESSED"},
        {'K', "KEY_K_PRESSED"},
        {'l', "KEY_L_PRESSED"},
        {'L', "KEY_L_PRESSED"},
        {'m', "KEY_M_PRESSED"},
        {'M', "KEY_M_PRESSED"},
        {'n', "KEY_N_PRESSED"},
        {'N', "KEY_N_PRESSED"},
        {'o', "KEY_O_PRESSED"},
        {'O', "KEY_O_PRESSED"},
        {'p', "KEY_P_PRESSED"},
        {'P', "KEY_P_PRESSED"},
        {'q', "KEY_Q_PRESSED"},
        {'Q', "KEY_Q_PRESSED"},
        {'r', "KEY_R_PRESSED"},
        {'R', "KEY_R_PRESSED"},
        {'s', "KEY_S_PRESSED"},
        {'S', "KEY_S_PRESSED"},
        {'t', "KEY_T_PRESSED"},
        {'T', "KEY_T_PRESSED"},
        {'u', "KEY_U_PRESSED"},
        {'U', "KEY_U_PRESSED"},
        {'v', "KEY_V_PRESSED"},
        {'V', "KEY_V_PRESSED"},
        {'w', "KEY_W_PRESSED"},
        {'W', "KEY_W_PRESSED"},
        {'x', "KEY_X_PRESSED"},
        {'X', "KEY_X_PRESSED"},
        {'y', "KEY_Y_PRESSED"},
        {'Y', "KEY_Y_PRESSED"},
        {'z', "KEY_Z_PRESSED"},
        {'Z', "KEY_Z_PRESSED"},
        {'0', "KEY_0_PRESSED"},
        {'1', "KEY_1_PRESSED"},
        {'2', "KEY_2_PRESSED"},
        {'3', "KEY_3_PRESSED"},
        {'4', "KEY_4_PRESSED"},
        {'5', "KEY_5_PRESSED"},
        {'6', "KEY_6_PRESSED"},
        {'7', "KEY_7_PRESSED"},
        {'8', "KEY_8_PRESSED"},
        {'9', "KEY_9_PRESSED"},
        {' ', "KEY_SPACE_PRESSED"},
        {KEY_ENTER, "KEY_ENTER_PRESSED"},
        {27, "KEY_ESC_PRESSED"},
        {KEY_UP, "KEY_UP_PRESSED"},
        {KEY_DOWN, "KEY_DOWN_PRESSED"},
        {KEY_LEFT, "KEY_LEFT_PRESSED"},
        {KEY_RIGHT, "KEY_RIGHT_PRESSED"},
        {9, "KEY_TAB_PRESSED"},
        {KEY_BACKSPACE, "KEY_BACKSPACE_PRESSED"},
        {KEY_DC, "KEY_DELETE_PRESSED"},
        {KEY_SLEFT, "KEY_SHIFT_PRESSED"},
        {KEY_SRIGHT, "KEY_SHIFT_PRESSED"},
        {17, "KEY_CTRL_PRESSED"},
        {18, "KEY_ALT_PRESSED"},
        {KEY_F(1), "KEY_F1_PRESSED"},
        {KEY_F(2), "KEY_F2_PRESSED"},
        {KEY_F(3), "KEY_F3_PRESSED"},
        {KEY_F(4), "KEY_F4_PRESSED"},
        {KEY_F(5), "KEY_F5_PRESSED"},
        {KEY_F(6), "KEY_F6_PRESSED"},
        {KEY_F(7), "KEY_F7_PRESSED"},
        {KEY_F(8), "KEY_F8_PRESSED"},
        {KEY_F(9), "KEY_F9_PRESSED"},
        {KEY_F(10), "KEY_F10_PRESSED"},
        {KEY_F(11), "KEY_F11_PRESSED"},
        {KEY_F(12), "KEY_F12_PRESSED"},
        {KEY_RESIZE, "WINDOW_RESIZE"},
        {KEY_MIN, "WINDOW_MINIMIZE"}
    };

    if (keys.find(key) != keys.end()) {
        std::string eventName = keys.find(key)->second;
        eventManager.addEvent(eventName, nullptr);
    }
}

void Arcade::Graph::NCursesSystem::run([[maybe_unused]] std::size_t deltaTime, Arcade::ECS::IEventManager &eventManager,
    [[maybe_unused]] Arcade::Core::IEntityManager &entityManager)
{
    std::vector<std::shared_ptr<IEntity>> &entities = entityManager.getEntities();

    displaySprites(entities);
    displayTexts(entities);
    captureKeyboardEvents(eventManager);

    refresh();
}
