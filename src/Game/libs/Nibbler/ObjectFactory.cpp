/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** ObjectFactory
*/

#include "ObjectFactory.hpp"
#include "NibblerGameScene.hpp"
#include "Transform.hpp"
#include "Direction.hpp"
#include "Speed.hpp"
#include "NibblerSprite.hpp"
#include "BoxCollider.hpp"
#include "NibblerHeadCollider.hpp"
#include "NibblerPath.hpp"

namespace Nibbler
{
    ObjectFactory::ObjectFactory()
    {
    }

    ObjectFactory::~ObjectFactory()
    {
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateNibblerHead(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("nibbler_head");
        auto transform
            = std::shared_ptr<Nibbler::Transform>(new Nibbler::Transform("Transform", position));
        auto speed = std::shared_ptr<Nibbler::Speed>(new Nibbler::Speed("Speed", SPEED_ENTITY * 1.005));

        speed->setNextPoint(
            { position.x / CASE_SIZE * CASE_SIZE, position.y / CASE_SIZE * CASE_SIZE, 0 });
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Nibbler::Direction>(
            new Nibbler::Direction("Direction", Direction::dir::UP)));
        entity.addComponent(speed);
        entity.addComponent(std::shared_ptr<Nibbler::Sprite>(new Nibbler::Sprite("Sprite", NIBBLER_HEAD_PATH,
            { "H", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, NIBBLER_SIZE, NIBBLER_SIZE }, 3)));
        entity.addComponent(std::shared_ptr<Nibbler::NibblerHeadCollider>(new Nibbler::NibblerHeadCollider(
            "NibblerCollider", { CASE_SIZE / 2, CASE_SIZE / 2, 0 }, *transform)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateNibblerBody(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position, Arcade::Vector3f rotation)
    {
        auto entities = entityManager.getEntities();
        int NibblerBodyCount = 0;

        for (auto &entity : entities) {
            std::string id = entity->getId();
            if (id.find("nibbler_body_") != std::string::npos) {
                NibblerBodyCount++;
            }
        }
        std::string id = "nibbler_body_" + std::to_string(NibblerBodyCount);
        auto &entity = entityManager.createEntity(id);
        (void)rotation;

        auto lastTail = entityManager.getEntitiesById("nibbler_body_" + std::to_string(NibblerBodyCount - 1));
        std::shared_ptr<Nibbler::NibblerPath> path;
        std::shared_ptr<Nibbler::Direction> direction;

        if (lastTail == nullptr) {
            path = std::shared_ptr<Nibbler::NibblerPath>(new Nibbler::NibblerPath("NibblerPath"));
            direction = std::shared_ptr<Nibbler::Direction>(new Nibbler::Direction("Direction", Direction::dir::UP));
        } else {
            auto lastTailPath = reinterpret_cast<Nibbler::NibblerPath &>(lastTail->getComponents("NibblerPath"));
            path = std::shared_ptr<Nibbler::NibblerPath>(new Nibbler::NibblerPath(lastTailPath));
            auto lastTailDirection = reinterpret_cast<Nibbler::Direction &>(lastTail->getComponents("Direction"));
            direction = std::shared_ptr<Nibbler::Direction>(new Nibbler::Direction(lastTailDirection));
        }
        auto transform = std::shared_ptr<Nibbler::Transform>(new Nibbler::Transform("Transform", position));
        auto boxCollider = std::shared_ptr<Nibbler::BoxCollider>(new Nibbler::BoxCollider("BoxCollider", {CASE_SIZE / 2, CASE_SIZE / 2, 0}, *transform));
        entity.addComponent(transform);
        entity.addComponent(path);
        entity.addComponent(direction);
        entity.addComponent(std::shared_ptr<Nibbler::Speed>(new Nibbler::Speed("Speed", SPEED_ENTITY)));
        entity.addComponent(std::shared_ptr<Nibbler::Sprite>(new Nibbler::Sprite("Sprite", NIBBLER_BODY_PATH,
            { "B", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, NIBBLER_SIZE, NIBBLER_SIZE }, 0)));
        entity.addComponent(boxCollider);
        if (NibblerBodyCount == 0) {
            boxCollider->isEnabled = false;
        }
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateFruit(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("fruit");
        auto transform
            = std::shared_ptr<Nibbler::Transform>(new Nibbler::Transform("Transform", position));
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Nibbler::Sprite>(new Nibbler::Sprite("sprite", FRUIT_PATH,
            { "F", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, FRUIT_SIZE, FRUIT_SIZE }, 0)));
        entity.addComponent(std::shared_ptr<Nibbler::BoxCollider>(
            new Nibbler::BoxCollider("BoxCollider", { CASE_SIZE, CASE_SIZE, 0 }, *transform)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateHorizontalWall(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("horizontal_wall");
        auto transform
            = std::shared_ptr<Nibbler::Transform>(new Nibbler::Transform("Transform", position));
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Nibbler::Sprite>(new Nibbler::Sprite("Sprite", HORIZONTAL_WALL_PATH,
            { "-", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, WALL_HEIGHT * 2, WALL_WIDTH }, 0)));
        entity.addComponent(std::shared_ptr<Nibbler::BoxCollider>(new Nibbler::BoxCollider(
            "BoxCollider", { CASE_SIZE, 2, 0 }, *transform)));
        return entity;
    }

    Arcade::ECS::IEntity &ObjectFactory::CreateVerticalWall(Arcade::ECS::IEntityManager &entityManager,
        Arcade::Vector3f position)
    {
        auto &entity = entityManager.createEntity("vertical_wall");
        auto transform
            = std::shared_ptr<Nibbler::Transform>(new Nibbler::Transform("Transform", position));
        entity.addComponent(transform);
        entity.addComponent(std::shared_ptr<Nibbler::Sprite>(new Nibbler::Sprite("Sprite", VERTICAL_WALL_PATH,
            { "|", { 255, 255, 255, 255 }, { 0, 0, 0, 255 } }, position,
            { 0, 0, WALL_WIDTH, WALL_HEIGHT }, 0)));
        entity.addComponent(std::shared_ptr<Nibbler::BoxCollider>(new Nibbler::BoxCollider(
            "BoxCollider", { 2, CASE_SIZE, 0 }, *transform)));
        return entity;
    }
} // namespace Nibbler
