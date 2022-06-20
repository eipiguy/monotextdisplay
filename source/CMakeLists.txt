cmake_minimum_required(VERSION 3.15)

project(monotextdisplay)
add_executable(monotextdisplay)
target_sources(monotextdisplay
    PRIVATE
    test.hpp
    test.cpp
    text_canvas.hpp
    text_canvas.cpp
    text_tile.hpp
)
