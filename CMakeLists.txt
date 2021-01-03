cmake_minimum_required(VERSION 3.10)
project(Kaleidoscope VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_executable(Kaleidoscope src/main.cpp)
target_include_directories(Kaleidoscope PUBLIC lib)
target_link_libraries(Kaleidoscope PUBLIC lib)
