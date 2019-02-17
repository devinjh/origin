cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

find_package(SFML COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})

add_executable(race main.cpp)
target_link_libraries(race ${SFML_LIBRARIES})

include_directories(images)