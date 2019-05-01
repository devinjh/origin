
# Minimum version of CMake required
cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

# Makes sure the SFML Graphics package is installed as it's necessary for this game
find_package(SFML COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})

# Adds all of the files together to make the race exectuable
add_executable(race main.cpp car.cpp object.cpp effect.cpp gameEvents.cpp)

# Links the SFML library to the race executable
target_link_libraries(race ${SFML_LIBRARIES})

# Includes the directory with all of the images to make sure that they display properly
include_directories(images)

# This automatically sets the display so when race is executed, the user doesn't have to
# worry about setting the display
#execute_process(COMMAND bash -c "export DISPLAY=:0") # DOES NOT WORK