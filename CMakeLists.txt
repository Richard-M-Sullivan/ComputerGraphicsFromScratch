cmake_minimum_required(VERSION 3.22.1)

project(scratch_graphics)

add_subdirectory(lib/canvas)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    SDL2
    canvas
)

include_directories(
    ${PROJECT_NAME}
    lib/canvas/
)