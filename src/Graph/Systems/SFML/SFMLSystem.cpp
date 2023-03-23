//
// Created by valegox on 23/03/23.
//

#include "SFMLSystem.hpp"
#include "IScene.hpp"
#include "IGameModule.hpp"
#include "Scene.hpp"
#include "ArcadeStruct.hpp"
#include "Component.hpp"
#include "ISprite.hpp"
#include "IText.hpp"
#include "IMusic.hpp"

Arcade::Graph::SFMLSystem::SFMLSystem()
{
    this->_window.create(sf::VideoMode(800, 600), "Arcade");
}

Arcade::Graph::SFMLSystem::~SFMLSystem()
{
 
}

void Arcade::Graph::SFMLSystem::drawSprites(std::unique_ptr<Arcade::Game::IScene> &scene)
{
    for (auto &entity : scene->getEntityManager().getEntities()) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> spriteComponents = entity->getComponents(Arcade::ECS::CompType::SPRITE);

        for (auto spriteComponent : spriteComponents) {
            auto sprite = std::static_pointer_cast<Arcade::Graph::ISprite>(spriteComponent);
            Arcade::Vector3f pos = (*sprite).getPos();
            Arcade::Vector3f size = (*sprite).getSize();
            Arcade::Graph::Rect rect = (*sprite).getRect();
            float scale = (*sprite).getScale();
            Arcade::Graph::Color color = (*sprite).getColor();

            sf::Texture texture;
            sf::Sprite sfSprite;
            sfSprite.setColor(sf::Color(color.r, color.g, color.b, color.a));
            if (texture.loadFromFile((*sprite).getPath())) {
                sfSprite.setTexture(texture);
            }
            sfSprite.setPosition(pos.x, pos.y);
            sfSprite.setScale(size.x * scale, size.y * scale);
            sfSprite.setTextureRect(sf::IntRect(rect.left, rect.top, rect.width, rect.height));
            this->_window.draw(sfSprite);
        }
    }
}

void Arcade::Graph::SFMLSystem::drawTexts(std::unique_ptr<Arcade::Game::IScene> &scene)
{
    for (auto &entity : scene->getEntityManager().getEntities()) {

        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> textComponents = entity->getComponents(Arcade::ECS::CompType::TEXT);

        for (auto textComponent : textComponents) {
            auto text = std::static_pointer_cast<Arcade::Graph::IText>(textComponent);
            Arcade::Vector2f pos = (*text).getPos();
            Arcade::Graph::Color foregroundColor = (*text).getForegroundColor();
            Arcade::Graph::Color backgroundColor = (*text).getBackgroundColor();

            sf::Font font;
            sf::Text sfText;
            sfText.setFillColor(sf::Color(foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a));
            sfText.setOutlineColor(sf::Color(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a));
            if (font.loadFromFile((*text).getFontPath())) {
                sfText.setFont(font);
            }
            sfText.setPosition(pos.x, pos.y);
            sfText.setString((*text).getText());
            sfText.setCharacterSize((*text).getPoliceSize());
            this->_window.draw(sfText);
        }
    }
}

void Arcade::Graph::SFMLSystem::handleMusics(std::unique_ptr<Arcade::Game::IScene> &scene)
{
    for (auto &entity : scene->getEntityManager().getEntities()) {
        std::vector<std::shared_ptr<Arcade::ECS::IComponent>> musicComponents = entity->getComponents(Arcade::ECS::CompType::MUSIC);

        for (auto musicComponent : musicComponents) {
            auto music = std::static_pointer_cast<Arcade::Graph::IMusic>(musicComponent);
            std::string id = (*music).getId();

            if ((*music).getIsPlaying() && !this->_playingMusics.contains(id)) {
                sf::Music *sfMusic = new sf::Music();
                if (sfMusic->openFromFile((*music).getPath())) {
                    sfMusic->play();
                    this->_playingMusics.insert(std::pair<std::string, std::unique_ptr<sf::Music>>(id, sfMusic));
                }
            } else if (!(*music).getIsPlaying() && this->_playingMusics.contains(id)) {
                this->_playingMusics.find(id)->second->stop();
                this->_playingMusics.erase(id);
            }

            if (this->_playingMusics.contains(id)) {
                this->_playingMusics.find(id)->second->setLoop((*music).getLoop());
                this->_playingMusics.find(id)->second->setVolume((*music).getVolume());
            }
        }
    }
}

void Arcade::Graph::SFMLSystem::captureEvents(Arcade::ECS::IEventManager &eventManager)
{
    const std::map<const char, const std::string> pressKeys = {
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
        {13, "KEY_ENTER_PRESSED"},
        {27, "KEY_ESC_PRESSED"},
        {38, "KEY_UP_PRESSED"},
        {40, "KEY_DOWN_PRESSED"},
        {37, "KEY_LEFT_PRESSED"},
        {39, "KEY_RIGHT_PRESSED"},
        {9, "KEY_TAB_PRESSED"},
        {8, "KEY_BACKSPACE_PRESSED"},
        {46, "KEY_DELETE_PRESSED"},
        {16, "KEY_SHIFT_PRESSED"},
        {16, "KEY_SHIFT_PRESSED"},
        {17, "KEY_CTRL_PRESSED"},
        {18, "KEY_ALT_PRESSED"},
        {112, "KEY_F1_PRESSED"},
        {113, "KEY_F2_PRESSED"},
        {114, "KEY_F3_PRESSED"},
        {115, "KEY_F4_PRESSED"},
        {116, "KEY_F5_PRESSED"},
        {117, "KEY_F6_PRESSED"},
        {118, "KEY_F7_PRESSED"},
        {119, "KEY_F8_PRESSED"},
        {120, "KEY_F9_PRESSED"},
        {121, "KEY_F10_PRESSED"},
        {122, "KEY_F11_PRESSED"},
        {123, "KEY_F12_PRESSED"},
    };

    const std::map<const sf::Mouse::Button, const std::string> pressMouse = {
        {sf::Mouse::Left, "MOUSE_KEY1_PRESSED"},
        {sf::Mouse::Right, "MOUSE_KEY2_PRESSED"},
        {sf::Mouse::Middle, "MOUSE_KEY3_PRESSED"},
        {sf::Mouse::XButton1, "MOUSE_KEY4_PRESSED"},
        {sf::Mouse::XButton2, "MOUSE_KEY5_PRESSED"},
    };

    sf::Event event;
    while (this->_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->_window.close();
                break;
            case sf::Event::KeyPressed:
                if (pressKeys.find(event.key.code) != pressKeys.end()) {
                    std::string eventName = pressKeys.find(event.key.code)->second;
                    eventManager.addEvent(eventName, nullptr);
                }
                break;
            case sf::Event::Resized:
                eventManager.addEvent("WINDOW_RESIZE", nullptr);
                break;
            case sf::Event::LostFocus:
                eventManager.addEvent("WINDOW_MINIMIZE", nullptr);
                break;
            case sf::Event::MouseButtonPressed:
                if (pressMouse.find(event.mouseButton.button) != pressMouse.end()) {
                    std::string eventName = pressMouse.find(event.mouseButton.button)->second;
                    eventManager.addEvent(eventName, nullptr);
                }
                break;
            default:
                break;
        }
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(this->_window);
    eventManager.setMousePosition(Arcade::Vector2f(mousePos.x, mousePos.y));
}

void Arcade::Graph::SFMLSystem::run([[maybe_unused]] std::size_t deltaTime, Arcade::ECS::IEventManager &eventManager,
    [[maybe_unused]] Arcade::Core::IDisplayModule &displayModule,
    Arcade::Core::IGameModule &gameModule)
{
    std::unique_ptr<Arcade::Game::IScene> &scene = gameModule.getSceneManager().getCurrentScene();

    this->_window.clear();
    this->drawSprites(scene);
    this->drawTexts(scene);
    this->_window.display();

    this->handleMusics(scene);

    this->captureEvents(eventManager);
}
