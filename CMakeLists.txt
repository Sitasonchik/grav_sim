cmake_minimum_required(VERSION 3.5)
project(grav_sim)

set(SFML_COMPONENTS graphics window system)

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/libs/SFML-WIN/include)
    link_directories(${CMAKE_SOURCE_DIR}/libs/SFML-WIN/lib)
elseif (UNIX)
    include_directories(${CMAKE_SOURCE_DIR}/libs/SFML/include)
    link_directories(${CMAKE_SOURCE_DIR}/libs/SFML/lib)
endif ()

include_directories(include)
include_directories(./)

add_executable(grav_sim src/main.cpp)


target_link_libraries(grav_sim sfml-graphics sfml-window sfml-system)
