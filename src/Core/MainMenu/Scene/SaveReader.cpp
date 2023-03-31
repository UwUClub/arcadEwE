//
// Created by patatofour on 28/03/23.
//

#include <fstream>
#include <iostream>
#include "SaveReader.hpp"
#include "Text.hpp"
#include "Core.hpp"

Arcade::Game::SaveReader::SaveReader()
{
}

void Arcade::Game::SaveReader::loadSave()
{
    std::string fileName = "save.txt";
    std::ifstream file(fileName, std::ios::ate);

    if (!file.is_open()) {
        throw SceneException("Failed to open file");
    }

    const size_t fileSize = file.tellg();
    char buffer[fileSize + 1] = { '\0' };

    if (file.bad()) {
        throw SceneException("Failed to read file");
    }
    file.seekg(0, std::ios::beg);
    if (!file.read(buffer, fileSize)) {
        throw SceneException("Failed to read file");
    }
    file.close();
    _saveContent = buffer;
}

bool Arcade::Game::SaveReader::init()
{
    size_t pos = 0;
    std::string line;
    float i = 0;

    try {
        loadSave();
        if (_saveContent.empty())
            return false;
        if (_saveContent.find('\n') == std::string::npos)
            return false;
        // for each line in the string _saveContent, create a new entity
        while ((pos = _saveContent.find('\n')) != std::string::npos) {
            line = _saveContent.substr(0, pos);
            _saveContent.erase(0, pos + 1);
            auto &entity = _entityManager->createEntity("Save" + std::to_string(i++));
            auto text = std::shared_ptr<Arcade::Game::Text>(
                new Arcade::Game::Text("text", line, FONT_PATH, { 0, 0, 0, 255 },
                    { 255, 255, 255, 255 }, { BASE_X_SAVE, (30 * (i + 1)), 0 }));
            entity.addComponent(text);
        }
    } catch (const SceneException &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}
