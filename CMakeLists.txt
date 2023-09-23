cmake_minimum_required(VERSION 3.27.4)

set(This CargoLoadingCalculator)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    main.hpp
)

set(Sources
    main.cpp
)

add_executable(${This} ${Sources})
add_library(lib${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)