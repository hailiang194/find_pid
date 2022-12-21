cmake_minimum_required(VERSION 3.1)
project(find_pid VERSION 1.0.0)

set(BUILD_EXAMPLE ON)

set(find_pid_public_headers
    src/find_pid.h
)

set(find_pid_sources
    src/find_pid.c
)

add_library(find_pid ${find_pid_public_headers} ${find_pid_sources})
file(COPY ${find_pid_public_headers} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

if(${BUILD_EXAMPLE} )
    add_subdirectory(example)
endif()