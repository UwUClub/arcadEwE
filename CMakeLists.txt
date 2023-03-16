cmake_minimum_required(VERSION 3.13)  # CMake version check
set(PROJECT_NAME arcade)
project(${PROJECT_NAME})               # Create project "arcade"
set(CMAKE_CXX_STANDARD 20)            # Enable c++14 standard
# add compilation flags to access dynamic library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fno-gnu-unique -fPIC")

# Add main.cpp file of project root directory as source file
set(EXEC_SRC
        sharedArchitecture/include/IGame.hpp
        sharedArchitecture/include/IGraph.hpp
        sharedArchitecture/include/ICore.hpp
        src/main.cpp
        src/Core.cpp
        src/Core.hpp
        src/LibraryHandler.cpp
        src/LibraryHandler.hpp
        )
set(EXECUTABLE arcade)
include_directories(sharedArchitecture/include)

# Add the SFML library to the project, uncomment the 2 line under
# if you want to use SFML:
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#add_executable(${PROJECT_NAME} ${SRC_FILES})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${EXECUTABLE} ${EXEC_SRC})
