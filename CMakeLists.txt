cmake_minimum_required(VERSION 3.10)
project(Kaleidoscope VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (search_paths
    ${PATH_TO_LLVM}
    ${PATH_TO_LLVM}/lib/cmake
    ${PATH_TO_LLVM}/lib/cmake/llvm
    ${PATH_TO_LLVM}/lib/cmake/clang
    ${PATH_TO_LLVM}/share/clang/cmake/
    ${PATH_TO_LLVM}/share/llvm/cmake/
    )

find_package(LLVM REQUIRED CONFIG
    PATHS ${search_paths}
    NO_DEFAULT_PATH)

message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

include_directories(include)
include_directories(${LLVM_INCLUDE_DIRS})
add_subdirectory(lib)

add_executable(Kaleidoscope src/main.cpp)
target_include_directories(Kaleidoscope PUBLIC ${LLVM_INCLUDE_DIRS})
target_link_libraries(Kaleidoscope PUBLIC lib LLVM)
