cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

set(HEAD_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(m26t3
    main.cpp
    User_Window.cpp
    Main_Window.cpp
    ${HEAD_DIR}/User_Window.h
    ${HEAD_DIR}/Main_Window.h

)

target_include_directories(m26t3 PUBLIC ${HEAD_DIR})
