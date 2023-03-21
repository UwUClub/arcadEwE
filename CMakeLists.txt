cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME arcade)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fno-gnu-unique -fPIC")


set(INCLUDES
        sharedArchitecture/include/Api.hpp
        sharedArchitecture/include/Arcade/ArcadeStruct.hpp
        sharedArchitecture/include/Arcade/Core/ICore.hpp
        sharedArchitecture/include/Arcade/Core/IGameModule.hpp
        sharedArchitecture/include/Arcade/Core/IDisplayModule.hpp
        sharedArchitecture/include/Arcade/ECS/IComponent.hpp
        sharedArchitecture/include/Arcade/ECS/IEntity.hpp
        sharedArchitecture/include/Arcade/ECS/IEntityManager.hpp
        sharedArchitecture/include/Arcade/ECS/IEventManager.hpp
        sharedArchitecture/include/Arcade/ECS/ISystemManager.hpp
        sharedArchitecture/include/Arcade/ECS/ISystem.hpp
        sharedArchitecture/include/Arcade/Graph/GraphStruct.hpp
        sharedArchitecture/include/Arcade/Graph/IMusic.hpp
        sharedArchitecture/include/Arcade/Graph/ISprite.hpp
        sharedArchitecture/include/Arcade/Graph/IText.hpp
        sharedArchitecture/include/Arcade/Game/IScene.hpp
        sharedArchitecture/include/Arcade/Game/ISceneManager.hpp
        )

# Add main.cpp file of project root directory as source file
set(EXEC_SRC
        src/main.cpp
        src/LibraryHandler.cpp
        src/LibraryHandler.hpp
        src/ECS/AComponent.cpp
        src/ECS/AComponent.hpp
        src/ECS/SystemManager.cpp
        src/ECS/SystemManager.hpp
        src/ECS/Entity.cpp
        src/ECS/Entity.hpp
        src/Core/Core.cpp
        src/Core/Core.hpp
        src/ECS/EventManager.cpp
        src/ECS/EventManager.hpp
        src/ECS/EntityManager.cpp
        src/ECS/EntityManager.hpp
        src/Core/DisplayModule.cpp
        src/Core/DisplayModule.hpp
        src/Core/GameModule.cpp
        src/Core/GameModule.hpp
        src/Game/Scene.cpp
        src/Game/Scene.hpp
        src/Game/SceneManager.cpp
        src/Game/SceneManager.hpp
        src/Graph/Music.cpp
        src/Graph/Music.hpp
        src/Graph/Sprite.cpp
        src/Graph/Sprite.hpp src/Graph/Text.cpp src/Graph/Text.hpp)

set(EXECUTABLE arcade)
include_directories(src)
include_directories(src/Core)
include_directories(src/ECS)
include_directories(src/Game)
include_directories(src/Graph)
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
add_executable(${EXECUTABLE} ${EXEC_SRC} ${INCLUDES})
