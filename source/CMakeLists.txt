#./CMakeLists.txt
cmake_minimum_required(VERSION 3.15)

project( monotextdisplay )
add_executable( monotextdisplay )
target_sources( monotextdisplay
    PRIVATE
        test.hpp
        test.cpp
        text_canvas.hpp
        text_canvas.cpp
)

if( WIN32 )
    target_sources( monotextdisplay
        PRIVATE
            terminal_abstraction_windows.cpp
    )
elseif( UNIX )
    target_sources( monotextdisplay
        PRIVATE
            terminal_abstraction_linux.cpp
    )
endif()