cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME arcade)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fno-gnu-unique -Wl,--no-as-needed -ldl")

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
        sharedArchitecture/include/Arcade/Graph/IDisplayModule.hpp
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
        src/Game/AGameModule.hpp
        src/Game/AGameModule.cpp
        src/Game/AScene.hpp
        src/Game/AScene.cpp
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
        src/Core/MainMenu/Scene/SelectionLib.cpp
        src/Core/MainMenu/Scene/SelectionLib.hpp
        src/Core/MainMenu/Scene/SaveReader.cpp
        src/Core/MainMenu/Scene/SaveReader.hpp
        src/Core/MainMenu/Components/Text.cpp
        src/Core/MainMenu/Components/Text.hpp
        src/Core/MainMenu/Components/IsHovered.cpp
        src/Core/MainMenu/Components/IsHovered.hpp
        src/Core/MainMenu/Systems/IsHovering.cpp
        src/Core/MainMenu/Systems/IsHovering.hpp
        src/Core/MainMenu/Systems/KeyboardHandler.cpp
        src/Core/MainMenu/Systems/KeyboardHandler.hpp
        src/ECS/Component.cpp
        src/Core/MainMenu/Scene/SaveReader.cpp
        src/Core/MainMenu/Scene/SaveReader.hpp)

include_directories(src)
include_directories(src/Core)
include_directories(src/Core/MainMenu)
include_directories(src/Core/MainMenu/Components)
include_directories(src/Core/MainMenu/Systems)
include_directories(src/Core/MainMenu/Scene)
include_directories(src/ECS)
include_directories(src/Game)
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
#add_subdirectory(src/Graph/libs/SDL)

# Graphical libraries
add_subdirectory(src/Graph/libs/NCurses)
# Games libraries
add_subdirectory(src/Game/libs/TestGame)
add_subdirectory(src/Game/libs/Snake)
# Core
add_executable(${PROJECT_NAME} ${EXEC_SRC} ${INCLUDES})
