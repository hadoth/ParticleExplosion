cmake_minimum_required(VERSION 3.7)
project(ParticleExplosion)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Simulation.cpp Simulation.h Particle.cpp Particle.h Swarm.cpp Swarm.h)
add_executable(ParticleExplosion ${SOURCE_FILES})
target_link_libraries(ParticleExplosion ${SDL2_LIBRARIES})

# instructions of STL configuration downloaded form https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/