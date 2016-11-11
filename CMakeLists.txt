cmake_minimum_required(VERSION 3.6)
project(Studienprojekt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES de,studienprojekt/main.cpp)
add_executable(Studienprojekt ${SOURCE_FILES})