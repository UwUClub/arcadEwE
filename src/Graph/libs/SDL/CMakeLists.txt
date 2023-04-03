cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME arcade_sdl2)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fno-gnu-unique -fPIC")

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

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
# Add main.cpp file of project root directory as source file
set(EXEC_SRC
        SdlDisplayModule.cpp
        SdlDisplayModule.hpp
        Systems/OnEvent.cpp
        Systems/OnEvent.hpp
        Api.cpp)

include_directories(.)
include_directories(Systems)
include_directories(../../../../sharedArchitecture/include)
include_directories(../../../../sharedArchitecture/include/Arcade)
include_directories(../../../../sharedArchitecture/include/Arcade/Core)
include_directories(../../../../sharedArchitecture/include/Arcade/ECS)
include_directories(../../../../sharedArchitecture/include/Arcade/Game)
include_directories(../../../../sharedArchitecture/include/Arcade/Graph)

# Add the SFML library to the project, uncomment the 2 line under
# if you want to use SFML:
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add executable target with source files listed in SOURCE_FILES variable
#add_subdirectory(src/Core/MainMenu)
add_library(${PROJECT_NAME} SHARED ${EXEC_SRC} ${INCLUDES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../../../../lib)