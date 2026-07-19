cmake_minimum_required(VERSION 3.20)

project(Clipper2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(clipper2
    src/clipper.engine.cpp
    src/clipper.offset.cpp
    src/clipper.rectclip.cpp
    src/clipper.triangulation.cpp
)
