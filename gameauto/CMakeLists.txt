cmake_minimum_required(VERSION 3.21)
project(gameauto)

set(CMAKE_CXX_STANDARD 20)
include_directories(gameauto)
set(PROJECT_HEADERS
        gameshop/gameshop.hpp
        autoverhuur/autoverhuur.hpp
        )
add_executable(gameauto
        gameshop/gameshop.cpp
        autoverhuur/main.cpp
        autoverhuur/autoverhuur.cpp)
