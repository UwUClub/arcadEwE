//
// Created by patatofour on 07/04/23.
//

#include <fstream>
#include "BufferWriterManager.hpp"
#include "IText.hpp"

Snake::BufferWriterManager::BufferWriterManager(size_t score)
    : _score(score)
{
}

void Snake::BufferWriterManager::run(double deltaTime, Arcade::ECS::IEventManager& eventManager,
    Arcade::ECS::IEntityManager& entityManager)
{
    auto entities = entityManager.getEntitiesByComponentType(Arcade::ECS::CompType::BUFFERTEXT);

    (void) deltaTime;
    for (auto& entity : *entities) {
        auto& bufferText = entity->getComponents(Arcade::ECS::CompType::TEXT);

        for (auto& text : bufferText) {
            auto buffer = std::static_pointer_cast<Arcade::Graph::IText>(text);
            auto events = getEventsTriggered(eventManager);

            for (auto& eventKey : events) {
                if (eventKey == "-1") {
                    buffer->text.pop_back();
                    continue;
                }
                if (eventKey == "ENTER") {
                    saveBuffer(buffer->text + " " + std::to_string(_score));
                    eventManager.addEvent(END_GAME);
                    return;
                }
                buffer->text += eventKey;
            }
        }
    }
}

std::vector<std::string> Snake::BufferWriterManager::getEventsTriggered(
    Arcade::ECS::IEventManager& eventManager)
{
    std::vector<std::string> events;

    for (auto& event : _keyMap) {
        if (eventManager.isEventTriggered(event.first).first) {
            events.push_back(event.second);
        }
    }
    return events;
}

void Snake::BufferWriterManager::saveBuffer(const std::string& buffer)
{
    std::ofstream ofs("save.txt", std::ofstream::out | std::ofstream::app);
    ofs << buffer << std::endl;
    ofs.close();
}
