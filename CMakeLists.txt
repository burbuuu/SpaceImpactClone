cmake_minimum_required(VERSION 3.10)
project(SpaceImpact CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Raylib using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

include_directories(${RAYLIB_INCLUDE_DIRS})
link_directories(${RAYLIB_LIBRARY_DIRS})

# Add source files (adjust this to your structure)
file(GLOB SOURCES
        src/*.cpp
        src/*.h
)

add_executable(${PROJECT_NAME} ${SOURCES})