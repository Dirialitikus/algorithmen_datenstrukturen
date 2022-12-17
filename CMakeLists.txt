cmake_minimum_required(VERSION 3.20)
project(algorithmen_datenstrukturen)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algorithmen_datenstrukturen
        graph.cpp
        graph.h)
