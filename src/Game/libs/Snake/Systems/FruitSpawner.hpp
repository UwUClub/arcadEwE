/*
** EPITECH PROJECT, 2023
** arcadEwE
** File description:
** FruitSpawner
*/

#ifndef FRUITSPAWNER_HPP_
    #define FRUITSPAWNER_HPP_
    #include "ISystem.hpp"
    #include "ArcadeStruct.hpp"

namespace Snake
{
    class FruitSpawner : public Arcade::ECS::ISystem
    {
        public:
            FruitSpawner() = default;
            ~FruitSpawner() override = default;

            void run(double deltaTime,
                Arcade::ECS::IEventManager &eventManager,
                Arcade::ECS::IEntityManager &entityManager) override;

        private:
            bool isFruitColliding(Arcade::ECS::IEntityManager &entityManager);

        private:
            bool SpawnFruit(Arcade::ECS::IEntityManager &entityManager);
    };
}

#endif /* !FRUITSPAWNER_HPP_ */
