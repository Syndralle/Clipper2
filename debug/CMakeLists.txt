cmake_minimum_required(VERSION 3.16)

project(DebugClipper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Clipper2 STATIC
    ../CPP/Clipper2Lib/src/clipper.engine.cpp
    ../CPP/Clipper2Lib/src/clipper.offset.cpp
    ../CPP/Clipper2Lib/src/clipper.rectclip.cpp
    ../CPP/Clipper2Lib/src/clipper.triangulation.cpp
)

target_include_directories(Clipper2 PUBLIC
    ../CPP/Clipper2Lib/include
)

add_executable(test
    main.cpp
)

target_link_libraries(test PRIVATE Clipper2)
