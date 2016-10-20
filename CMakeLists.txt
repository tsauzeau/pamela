cmake_minimum_required(VERSION 3.6)
project(pamela)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES
        include/defines.h
    include/Exception.hh
        include/Logger.hh
        src/Exception.cpp
    src/Logger.cpp
        src/pam.cpp)

add_library(pam_pamela SHARED ${SOURCE_FILES})