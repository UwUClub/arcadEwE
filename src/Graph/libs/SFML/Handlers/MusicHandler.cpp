//
// Created by valegox on 04/04/23.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "SFMLDisplayModule.hpp"
#include "MusicHandler.hpp"
#include "ArcadeStruct.hpp"
#include "IComponent.hpp"
#include "IMusic.hpp"

namespace Arcade::Graph
{

    void MusicHandler::run(Arcade::ECS::IEntityManager &entityManager)
    {
        for (auto &entity : entityManager.getEntities()) {

            if (entity->getComponents().find(Arcade::ECS::CompType::MUSIC) == entity->getComponents().end()) {
                continue;
            }

            std::vector<std::shared_ptr<Arcade::ECS::IComponent>> musicComponents
                = entity->getComponents(Arcade::ECS::CompType::MUSIC);

            for (auto musicComponent : musicComponents) {
                auto music = std::static_pointer_cast<Arcade::Graph::IMusic>(musicComponent);
                std::string id = (*music).id;

                if ((*music).play && !_playingMusics.contains(id)) {
                    sf::Music *sfMusic = new sf::Music();
                    if (sfMusic->openFromFile((*music).path)) {
                        sfMusic->play();
                        _playingMusics.insert(std::pair<std::string, std::unique_ptr<sf::Music>>(id, sfMusic));
                    }
                } else if (!(*music).play && _playingMusics.contains(id)) {
                    _playingMusics.find(id)->second->stop();
                    _playingMusics.erase(id);
                }

                if (_playingMusics.contains(id)) {
                    _playingMusics.find(id)->second->setLoop((*music).loop);
                    _playingMusics.find(id)->second->setVolume(10);
                }
            }
        }
    }
} // namespace Arcade::Graph
