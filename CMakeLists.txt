cmake_minimum_required(VERSION 2.8)
project(pamela)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES
        include/Exception.hh
	include/Utils.hh
        include/Logger.hh
	include/Crypt.hh
        src/Exception.cpp
        src/Logger.cpp
        src/pam.cpp
	src/Crypt.cpp
	src/Utils.cpp)

add_library(pam_pamela SHARED ${SOURCE_FILES})

find_package(PAM REQUIRED)
if (PAM_FOUND)
    include_directories(${PAM_INCLUDE_DIR})
    target_link_libraries(pam_pamela ${PAM_LIBRARIES})
endif (PAM_FOUND)

find_package(CRYPTSETUP REQUIRED)
if (CRYPTSETUP_FOUND)
    include_directories(${CRYPTSETUP_INCLUDE_DIR})
    target_link_libraries(pam_pamela ${CRYPTSETUP_LIBRARIES})
endif (CRYPTSETUP_FOUND)

INSTALL(TARGETS pam_pamela DESTINATION /lib/x86_64-linux-gnu/security/)
