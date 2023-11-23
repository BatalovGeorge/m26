cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

set(DIR_HEAD ${CMAKE_SOURCE_DIR}/include)

add_executable(m26t2
    main.cpp
    Mobile_Telephone.cpp
    Contact.cpp
    ${DIR_HEAD}/Mobile_Telephone.h
    ${DIR_HEAD}/Contact.h)

target_include_directories(m26t2 PUBLIC ${DIR_HEAD})
