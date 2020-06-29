cmake_minimum_required(VERSION 3.1)

project(server_main)

set(SOURCE_EXE main.cpp)

add_executable(server_main ${SOURCE_EXE})

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.65.0 REQUIRED system)

if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(server_main ${Boost_LIBRARIES})
endif()

add_library(server_lib STATIC server.cpp)
add_library(session_lib STATIC session.cpp)
target_link_libraries(server_main server_lib session_lib)

