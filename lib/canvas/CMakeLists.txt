cmake_minimum_required(VERSION 3.22.1)

project(canvas)

add_library(
    ${PROJECT_NAME} STATIC
    canvas.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    SDL2
)