cmake_minimum_required(VERSION 3.20)
project(MarineNavStarter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(marine_nav_lib
    src/gps_parser.cpp
    src/route_planner.cpp
)
target_include_directories(marine_nav_lib PUBLIC include)

add_executable(marine_nav
    src/main.cpp
)
target_link_libraries(marine_nav PRIVATE marine_nav_lib)
target_include_directories(marine_nav PRIVATE include)

# --- Tests ---
find_package(Boost 1.74 REQUIRED COMPONENTS unit_test_framework)

add_executable(tests
    tests/test_main.cpp
    tests/test_utils.cpp
    tests/test_gps_parser.cpp
    tests/test_route_planner.cpp
)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE marine_nav_lib Boost::unit_test_framework)
target_compile_definitions(tests PRIVATE BOOST_TEST_DYN_LINK)