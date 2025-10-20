cmake_minimum_required(VERSION 3.10)
project(SpaceImpact CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files recursively
file(GLOB_RECURSE SOURCES
        src/*.cpp
        src/*.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES}
        src/Game/Player.cpp
        src/Game/Player.h
        src/Game/Bullet.cpp
        src/Game/Bullet.h
        src/Game/Managers/BulletManager.cpp
        src/Game/Managers/BulletManager.h
        src/Game/Managers/EnemyManager.cpp
        src/Game/Managers/EnemyManager.h
        src/Game/Enemies/BaseEnemy.cpp
        src/Game/Enemies/BaseEnemy.h
        src/Game/Enemies/Enemy1.cpp
        src/Game/Enemies/Enemy1.h
)

# Include source directory
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

# If Raylib is in /usr/local/lib and /usr/local/include
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# Link Raylib and required dependencies
target_link_libraries(${PROJECT_NAME}
        raylib
        m
        pthread
        dl
        rt
        X11
)
