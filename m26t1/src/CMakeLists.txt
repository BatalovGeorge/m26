cmake_minimum_required(VERSION 3.5)

set(DIR_HEAD ${CMAKE_SOURCE_DIR}/include)

add_executable(m26t1
    main.cpp
    Track.cpp
    Music_player.cpp
    ${DIR_HEAD}/Track.h
    ${DIR_HEAD}/Music_player.h)

target_include_directories(m26t1 PUBLIC ${DIR_HEAD})
