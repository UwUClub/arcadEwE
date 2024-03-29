cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME arcade_snake_game)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fno-gnu-unique -fPIC")

set(INCLUDES
        ../../../../sharedArchitecture/include/Api.hpp
        ../../../../sharedArchitecture/include/Arcade/ArcadeStruct.hpp
        ../../../../sharedArchitecture/include/Arcade/Core/ICore.hpp
        ../../../../sharedArchitecture/include/Arcade/Game/IGameModule.hpp
        ../../../../sharedArchitecture/include/Arcade/Graph/IDisplayModule.hpp
        ../../../../sharedArchitecture/include/Arcade/ECS/IComponent.hpp
        ../../../../sharedArchitecture/include/Arcade/ECS/IEntity.hpp
        ../../../../sharedArchitecture/include/Arcade/ECS/IEntityManager.hpp
        ../../../../sharedArchitecture/include/Arcade/ECS/IEventManager.hpp
        ../../../../sharedArchitecture/include/Arcade/ECS/ISystemManager.hpp
        ../../../../sharedArchitecture/include/Arcade/Graph/GraphStruct.hpp
        ../../../../sharedArchitecture/include/Arcade/Graph/IMusic.hpp
        ../../../../sharedArchitecture/include/Arcade/Graph/ISprite.hpp
        ../../../../sharedArchitecture/include/Arcade/Graph/IText.hpp
        ../../../../sharedArchitecture/include/Arcade/Graph/IDisplayModule.hpp
        ../../../../sharedArchitecture/include/Arcade/Game/IScene.hpp
        )

# Add main.cpp file of project root directory as source file
set(EXEC_SRC
        Api.cpp
        Components/BoxCollider.cpp
        Components/BoxCollider.hpp
        Components/Direction.cpp
        Components/Direction.hpp
        Components/Transform.cpp
        Components/Transform.hpp
        Components/SnakeHeadCollider.cpp
        Components/SnakeHeadCollider.hpp
        Components/SnakeIsHovered.cpp
        Components/SnakeIsHovered.hpp
        Components/SnakePath.cpp
        Components/SnakePath.hpp
        Components/SnakeText.cpp
        Components/SnakeText.hpp
        Components/Speed.cpp
        Components/Speed.hpp
        Components/SnakeSprite.cpp
        Components/SnakeSprite.hpp
        Scenes/SnakeGameOverScene.cpp
        Scenes/SnakeGameOverScene.hpp
        Scenes/SnakeGameScene.cpp
        Scenes/SnakeGameScene.hpp
        Scenes/SnakeMenuScene.cpp
        Scenes/SnakeMenuScene.hpp
        Scenes/SnakeScene.cpp
        Scenes/SnakeScene.hpp
        Systems/ColliderManager.cpp
        Systems/ColliderManager.hpp
        Systems/FruitSpawner.cpp
        Systems/FruitSpawner.hpp
        Systems/MenuKeyboardHandler.cpp
        Systems/MenuKeyboardHandler.hpp
        Systems/MoveSnake.cpp
        Systems/MoveSnake.hpp
        Systems/MoveTail.cpp
        Systems/MoveTail.hpp
        Systems/PlayerInputs.cpp
        Systems/PlayerInputs.hpp
        Systems/SnakeGameManager.cpp
        Systems/SnakeGameManager.hpp
        Systems/SnakeIsHovering.cpp
        Systems/SnakeIsHovering.hpp
        Systems/SnakeTailManager.cpp
        Systems/SnakeTailManager.hpp
        Systems/TransformDisplay.cpp
        Systems/TransformDisplay.hpp
        ObjectFactory.cpp
        ObjectFactory.hpp
        SnakeGameModule.cpp
        SnakeGameModule.hpp
        ../../AGameModule.hpp
        ../../AGameModule.cpp
        ../../AScene.hpp
        ../../AScene.cpp
        ../../../ECS/SystemManager.hpp
        ../../../ECS/SystemManager.cpp
        ../../../ECS/EntityManager.hpp
        ../../../ECS/EntityManager.cpp
        ../../../ECS/Entity.hpp
        ../../../ECS/Entity.cpp
        ../../../ECS/Component.hpp
        ../../../ECS/Component.cpp
        Components/BufferText.cpp
        Components/BufferText.hpp
        Systems/BufferWriterManager.cpp
        Systems/BufferWriterManager.hpp)

include_directories(.)
include_directories(Components)
include_directories(Systems)
include_directories(Scenes)
include_directories(../../)
include_directories(../../../ECS)
include_directories(../../../../sharedArchitecture/include)
include_directories(../../../../sharedArchitecture/include/Arcade)
include_directories(../../../../sharedArchitecture/include/Arcade/Core)
include_directories(../../../../sharedArchitecture/include/Arcade/ECS)
include_directories(../../../../sharedArchitecture/include/Arcade/Game)
include_directories(../../../../sharedArchitecture/include/Arcade/Graph)

# Add executable target with source files listed in SOURCE_FILES variable
add_library(${PROJECT_NAME} SHARED ${EXEC_SRC} ${INCLUDES})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../../../../lib PREFIX "")
