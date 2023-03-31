cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME arcade)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wl,--no-as-needed -ldl -fno-gnu-unique -fPIC")

set(INCLUDES
    sharedArchitecture/include/Api.hpp
    sharedArchitecture/include/Arcade/ArcadeStruct.hpp
    sharedArchitecture/include/Arcade/Core/ICore.hpp
    sharedArchitecture/include/Arcade/Game/IGameModule.hpp
    sharedArchitecture/include/Arcade/Graph/IDisplayModule.hpp
    sharedArchitecture/include/Arcade/ECS/IComponent.hpp
    sharedArchitecture/include/Arcade/ECS/IEntity.hpp
    sharedArchitecture/include/Arcade/ECS/IEntityManager.hpp
    sharedArchitecture/include/Arcade/ECS/IEventManager.hpp
    sharedArchitecture/include/Arcade/ECS/ISystemManager.hpp
    sharedArchitecture/include/Arcade/Graph/GraphStruct.hpp
    sharedArchitecture/include/Arcade/Graph/IMusic.hpp
    sharedArchitecture/include/Arcade/Graph/ISprite.hpp
    sharedArchitecture/include/Arcade/Graph/IText.hpp
    sharedArchitecture/include/Arcade/Game/IScene.hpp
    )

# Add main.cpp file of project root directory as source file
set(EXEC_SRC
        src/main.cpp
        src/Library/DisplayHandler.hpp
        src/Library/DisplayHandler.cpp
        src/Library/GameHandler.hpp
        src/Library/GameHandler.cpp
        src/Library/LibraryFinder.cpp
        src/Library/LibraryFinder.hpp
        src/Core/Core.cpp
        src/Core/Core.hpp
        src/ECS/EventManager.cpp
        src/ECS/EventManager.hpp
        src/ECS/SystemManager.cpp
        src/ECS/SystemManager.hpp
        src/ECS/EntityManager.cpp
        src/ECS/EntityManager.hpp
        src/ECS/Entity.cpp
        src/ECS/Entity.hpp
        src/Core/MainMenu/MainMenu.cpp
        src/Core/MainMenu/MainMenu.hpp
        src/Core/MainMenu/Scene/MainMenuScene.cpp
        src/Core/MainMenu/Scene/MainMenuScene.hpp
        src/Core/MainMenu/Scene/SelectionLib.cpp
        src/Core/MainMenu/Scene/SelectionLib.hpp
        src/Core/MainMenu/Components/Text.cpp
        src/Core/MainMenu/Components/Text.hpp
        src/Core/MainMenu/Components/IsHovered.cpp
        src/Core/MainMenu/Components/IsHovered.hpp
        src/Core/MainMenu/Systems/IsHovering.cpp
        src/Core/MainMenu/Systems/IsHovering.hpp
        src/Core/MainMenu/Systems/KeyboardHandler.cpp
        src/Core/MainMenu/Systems/KeyboardHandler.hpp
        src/ECS/Component.cpp src/Core/MainMenu/Scene/SaveReader.cpp src/Core/MainMenu/Scene/SaveReader.hpp)

include_directories(src)
include_directories(src/Core)
include_directories(src/Core/MainMenu)
include_directories(src/Core/MainMenu/Components)
include_directories(src/Core/MainMenu/Systems)
include_directories(src/Core/MainMenu/Scene)
include_directories(src/ECS)
include_directories(src/Library)
include_directories(sharedArchitecture/include)
include_directories(sharedArchitecture/include/Arcade)
include_directories(sharedArchitecture/include/Arcade/Core)
include_directories(sharedArchitecture/include/Arcade/ECS)
include_directories(sharedArchitecture/include/Arcade/Game)
include_directories(sharedArchitecture/include/Arcade/Graph)

# Add the SFML library to the project, uncomment the 2 line under
# if you want to use SFML:
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add executable target with source files listed in SOURCE_FILES variable
#add_subdirectory(src/Core/MainMenu)
add_executable(${PROJECT_NAME} ${EXEC_SRC} ${INCLUDES})


# ------------------------------------------------------------------------------
# Compile the Snake game shared library
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.9)
include(GNUInstallDirs)
set(SNAKE_VERSION 1.0.0)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

project(arcade_snake
    VERSION ${SNAKE_VERSION}
    DESCRIPTION "Snake game for the arcade"
    LANGUAGES CXX)

set(SNAKE_SOURCES
    lib/Snake/Components/Direction.cpp
    lib/Snake/Components/Direction.hpp
    lib/Snake/Components/Position.cpp
    lib/Snake/Components/Position.hpp
    lib/Snake/Components/SnakeIsHovered.cpp
    lib/Snake/Components/SnakeIsHovered.hpp
    lib/Snake/Components/SnakeText.cpp
    lib/Snake/Components/SnakeText.hpp
    lib/Snake/Components/Speed.cpp
    lib/Snake/Components/Speed.hpp
    lib/Snake/Components/Sprite.cpp
    lib/Snake/Components/Sprite.hpp
    lib/Snake/Scenes/SnakeGameScene.cpp
    lib/Snake/Scenes/SnakeGameScene.hpp
    lib/Snake/Scenes/SnakeMenuScene.cpp
    lib/Snake/Scenes/SnakeMenuScene.hpp
    lib/Snake/Scenes/SnakeScene.cpp
    lib/Snake/Scenes/SnakeScene.hpp
    lib/Snake/Systems/MenuKeyboardHandler.cpp
    lib/Snake/Systems/MenuKeyboardHandler.hpp
    lib/Snake/Systems/MoveSnake.cpp
    lib/Snake/Systems/MoveSnake.hpp
    lib/Snake/Systems/PlayerInputs.cpp
    lib/Snake/Systems/PlayerInputs.hpp
    lib/Snake/Systems/SnakeGameManager.cpp
    lib/Snake/Systems/SnakeGameManager.hpp
    lib/Snake/Systems/SnakeIsHovering.cpp
    lib/Snake/Systems/SnakeIsHovering.hpp
    lib/Snake/Snake.cpp
    lib/Snake/Snake.hpp)

add_library(arcade_snake SHARED
    ${SNAKE_SOURCES} ${INCLUDES})

set_target_properties(arcade_snake PROPERTIES
    VERSION ${SNAKE_VERSION}
    DESCRIPTION "Snake game for the arcade")

target_include_directories(arcade_snake PRIVATE lib/Snake)
target_include_directories(arcade_snake PRIVATE lib/Snake/Components)
target_include_directories(arcade_snake PRIVATE lib/Snake/Systems)
target_include_directories(arcade_snake PRIVATE lib/Snake/Scenes)
target_include_directories(arcade_snake PRIVATE src)
target_include_directories(arcade_snake PRIVATE src/Core)
target_include_directories(arcade_snake PRIVATE src/Core/MainMenu)
target_include_directories(arcade_snake PRIVATE src/Core/MainMenu/Components)
target_include_directories(arcade_snake PRIVATE src/Core/MainMenu/Systems)
target_include_directories(arcade_snake PRIVATE src/Core/MainMenu/Scene)
target_include_directories(arcade_snake PRIVATE src/ECS)
target_include_directories(arcade_snake PRIVATE src/Library)
target_include_directories(arcade_snake PRIVATE sharedArchitecture/include)
target_include_directories(arcade_snake PRIVATE sharedArchitecture/include/Arcade)
target_include_directories(arcade_snake PRIVATE sharedArchitecture/include/Arcade/Core)
target_include_directories(arcade_snake PRIVATE sharedArchitecture/include/Arcade/ECS)
target_include_directories(arcade_snake PRIVATE sharedArchitecture/include/Arcade/Game)
target_include_directories(arcade_snake PRIVATE sharedArchitecture/include/Arcade/Graph)

install(TARGETS arcade_snake
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
