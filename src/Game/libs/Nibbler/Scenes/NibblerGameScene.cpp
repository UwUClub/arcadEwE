/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** NibblerGameScene
*/

#include "NibblerGameScene.hpp"
#include "SystemManager.hpp"
#include "PlayerInputs.hpp"
#include "MoveNibbler.hpp"
#include "MoveTail.hpp"
#include "ObjectFactory.hpp"
#include "ColliderManager.hpp"
#include "FruitSpawner.hpp"
#include "ColliderManager.hpp"
#include "ArcadeStruct.hpp"
#include "TransformDisplay.hpp"
#include "NibblerGameManager.hpp"
#include "NibblerTailManager.hpp"

namespace Nibbler {
    NibblerGameScene::NibblerGameScene() : NibblerScene()
    {
    }

    bool NibblerGameScene::init()
    {
        ObjectFactory objectFactory;

        if (_entityManager == nullptr)
            _entityManager = std::make_unique<Arcade::ECS::EntityManager>();
        if (_systemManager == nullptr)
            _systemManager = std::make_unique<Arcade::ECS::SystemManager>();

        _systemManager->addSystem("PlayerInputs", std::make_unique<Nibbler::PlayerInputs>());
        _systemManager->addSystem("MoveNibbler", std::make_unique<Nibbler::MoveNibbler>());
        _systemManager->addSystem("FruitSpawner", std::make_unique<Nibbler::FruitSpawner>());
        _systemManager->addSystem("TransformDisplay", std::make_unique<Nibbler::TransformDisplay>());
        _systemManager->addSystem("NibblerGameManager", std::make_unique<Nibbler::NibblerGameManager>());
        _systemManager->addSystem("ColliderManager", std::make_unique<Nibbler::ColliderManager>());
        _systemManager->addSystem("MoveTail", std::make_unique<Nibbler::MoveTail>());
        _systemManager->addSystem("NibblerTailManager", std::make_unique<Nibbler::NibblerTailManager>());

        objectFactory.CreateNibblerHead(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, MAX_CASE_Y / 2 * CASE_SIZE, 0});
        objectFactory.CreateNibblerBody(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_Y / 2 + 1) * CASE_SIZE, 0}, {0, 0, 0});
        objectFactory.CreateNibblerBody(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_Y / 2 + 2) * CASE_SIZE, 0}, {0, 0, 0});
        objectFactory.CreateNibblerBody(*_entityManager, {MAX_CASE_X / 2 * CASE_SIZE, (MAX_CASE_Y / 2 + 3) * CASE_SIZE, 0}, {0, 0, 0});

        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {(MAX_CASE_X - 1) * CASE_SIZE - WALL_OFFSET_X, CASE_SIZE - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2) - WALL_OFFSET_X, CASE_SIZE - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2 + 1) - WALL_OFFSET_X, CASE_SIZE - WALL_OFFSET_Y, 0});

        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {MAX_CASE_X * CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * 2 - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {(MAX_CASE_X - 1) * CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 2- WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {(MAX_CASE_X - 1) * CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2 - 1) - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2 + 1) - WALL_OFFSET_X, CASE_SIZE * 2 - WALL_OFFSET_Y, 0});

        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 3 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {(MAX_CASE_X - 1) * CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 3 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2 - 1) - WALL_OFFSET_X, CASE_SIZE * 3 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2) - WALL_OFFSET_X, CASE_SIZE * 3 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X / 2 + 1) - WALL_OFFSET_X, CASE_SIZE * 3 - WALL_OFFSET_Y, 0});

        objectFactory.CreateHorizontalWall(*_entityManager, {0, CASE_SIZE * 4 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * MAX_CASE_X - WALL_OFFSET_X, CASE_SIZE * 4 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 2 - WALL_OFFSET_X, CASE_SIZE * 4 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 2) - WALL_OFFSET_X, CASE_SIZE * 4 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 3 - WALL_OFFSET_X, CASE_SIZE * 4 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 3) - WALL_OFFSET_X, CASE_SIZE * 4 - WALL_OFFSET_Y, 0});

        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 1) - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 2 - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 2) - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 3 - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 3) - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * 4 - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 3) - WALL_OFFSET_X, CASE_SIZE * 5 - WALL_OFFSET_Y, 0});

        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 6 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 1) - WALL_OFFSET_X, CASE_SIZE * 6 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 2 - WALL_OFFSET_X, CASE_SIZE * 6 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 2) - WALL_OFFSET_X, CASE_SIZE * 6 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * 3 - WALL_OFFSET_X, CASE_SIZE * 6 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 2) - WALL_OFFSET_X, CASE_SIZE * 6 - WALL_OFFSET_Y, 0});

        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE - WALL_OFFSET_X, CASE_SIZE * 7 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * MAX_CASE_X - WALL_OFFSET_X, CASE_SIZE * 7 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * 2 - WALL_OFFSET_X, CASE_SIZE * 7 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 1) - WALL_OFFSET_X, CASE_SIZE * 7 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * 4 - WALL_OFFSET_X, CASE_SIZE * 7 - WALL_OFFSET_Y, 0});
        objectFactory.CreateVerticalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 3) - WALL_OFFSET_X, CASE_SIZE * 7 - WALL_OFFSET_Y, 0});

        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 2 - WALL_OFFSET_X, CASE_SIZE * 8 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 2) - WALL_OFFSET_X, CASE_SIZE * 8 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * 3 - WALL_OFFSET_X, CASE_SIZE * 8 - WALL_OFFSET_Y, 0});
        objectFactory.CreateHorizontalWall(*_entityManager, {CASE_SIZE * (MAX_CASE_X - 3) - WALL_OFFSET_X, CASE_SIZE * 8 - WALL_OFFSET_Y, 0});
        return true;
    }
}
