cmake_minimum_required(VERSION 3.5)
project(grav_sim)

set(SFML_COMPONENTS graphics window system)


include_directories(${CMAKE_SOURCE_DIR}/SFML/include)
link_directories(${CMAKE_SOURCE_DIR}/SFML/lib)

include_directories(include)
include_directories(./)

add_executable(grav_sim src/main.cpp)


target_link_libraries(grav_sim sfml-graphics sfml-window sfml-system)
