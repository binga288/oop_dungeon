cmake_minimum_required(VERSION 3.12)
project(Dungeon_Project)

# add all the include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# add all the source files
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# add the executable
add_executable(Dungeon_Project ${SOURCES})