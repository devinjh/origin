cmake_minimum_required(VERSION 3.0)
project(War)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classifications.cpp deck.cpp)
add_executable(war ${SOURCE_FILES})