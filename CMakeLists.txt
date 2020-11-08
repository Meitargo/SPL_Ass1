cmake_minimum_required(VERSION 3.17)
project(ASS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(ASS1
        include/Agent.h
        include/Graph.h
        include/json.hpp
        include/Session.h
        include/Tree.h
        src/Agent.cpp
        src/Graph.cpp
        src/main.cpp
        src/Session.cpp
        src/Tree.cpp)
