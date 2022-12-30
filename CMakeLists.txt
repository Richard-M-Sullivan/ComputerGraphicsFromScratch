cmake_minimum_required(VERSION 3.22.1)

project(scratch_graphics)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    canvas.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    SDL2
)