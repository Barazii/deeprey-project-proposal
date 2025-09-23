cmake_minimum_required(VERSION 3.20)
project(MarineNavStarter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(marine_nav
    src/main.cpp
    src/gps_parser.cpp
    src/route_planner.cpp
)

target_include_directories(marine_nav PRIVATE include)